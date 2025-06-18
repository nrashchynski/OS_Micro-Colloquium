#include <memory>
#include <thread>
#include "nodes/Disk.h"
#include "nodes/Directory.h"
#include "nodes/TextFile.h"
#include "nodes/ImageFile.h"
#include "visitors/CalculateSizeVisitor.h"
#include "visitors/PrintStructureVisitor.h"
#include "ThreadSafeFileSystem.h"
#include "strategies/MutexStrategy.h"

int main() {
    auto disk = std::make_shared<Disk>("C:");
    auto docs = std::make_shared<Directory>("Documents");
    auto pics = std::make_shared<Directory>("Pictures");

    auto notes = std::make_shared<TextFile>("notes.txt", 1500);
    auto config = std::make_shared<TextFile>("config.cfg", 800);
    auto photo = std::make_shared<ImageFile>("photo.jpg", 3500);
    auto screenshot = std::make_shared<ImageFile>("screen.png", 2800);

    docs->addChild(notes);
    docs->addChild(config);
    pics->addChild(photo);
    pics->addChild(screenshot);
    disk->addChild(docs);
    disk->addChild(pics);

    CalculateSizeVisitor sizeVisitor;
    PrintStructureVisitor printVisitor;

    ThreadSafeFileSystem<MutexStrategy> fs(disk);

    std::thread t1([&fs, &printVisitor]() {
        fs.performOperation(printVisitor);
        });

    std::thread t2([&fs, &sizeVisitor]() {
        fs.performOperation(sizeVisitor);
        });

    t1.join();
    t2.join();

    return 0;
}