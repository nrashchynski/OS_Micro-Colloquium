#include <gtest/gtest.h>
#include <thread>
#include <vector>
#include <atomic>
#include "../src/nodes/Disk.h"
#include "../src/nodes/Directory.h"
#include "../src/nodes/TextFile.h"
#include "../src/visitors/CalculateSizeVisitor.h"
#include "../src/ThreadSafeFileSystem.h"
#include "../src/strategies/MutexStrategy.h"

TEST(ThreadSafetyTest, ConcurrentSizeCalculation) {
    auto disk = std::make_shared<Disk>("TestDisk");
    auto dir = std::make_shared<Directory>("TestDir");
    auto file1 = std::make_shared<TextFile>("file1.txt", 100);
    auto file2 = std::make_shared<TextFile>("file2.txt", 200);

    dir->addChild(file1);
    dir->addChild(file2);
    disk->addChild(dir);

    ThreadSafeFileSystem<MutexStrategy> fs(disk);
    std::vector<std::thread> threads;
    const int threadCount = 10;
    std::vector<size_t> results(threadCount);

    for (int i = 0; i < threadCount; ++i) {
        threads.emplace_back([&fs, &results, i]() {
            CalculateSizeVisitor visitor;
            fs.performOperation(visitor);
            results[i] = visitor.getTotalSize();
            });
    }

    for (auto& t : threads) {
        t.join();
    }

    for (auto size : results) {
        EXPECT_EQ(size, 300);
    }
}

TEST(ThreadSafetyTest, NoDataRace) {
    auto disk = std::make_shared<Disk>("TestDisk");
    ThreadSafeFileSystem<MutexStrategy> fs(disk);
    std::atomic<bool> stop(false);
    std::atomic<int> counter(0);

    std::thread writer([&fs, &stop]() {
        while (!stop) {
            auto dir = std::make_shared<Directory>("Temp");
            fs.performOperation([&dir](auto& root) {
                dynamic_cast<Disk&>(root).addChild(dir);
                });
        }
        });

    std::thread reader([&fs, &stop, &counter]() {
        while (!stop) {
            CalculateSizeVisitor visitor;
            fs.performOperation(visitor);
            counter++;
        }
        });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    stop = true;
    writer.join();
    reader.join();

    EXPECT_GT(counter.load(), 0);
}