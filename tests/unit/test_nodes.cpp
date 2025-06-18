#include <gtest/gtest.h>
#include "../src/nodes/Disk.h"
#include "../src/nodes/Directory.h"
#include "../src/nodes/TextFile.h"
#include "../src/nodes/ImageFile.h"
#include "../src/visitors/CalculateSizeVisitor.h"
#include "../src/visitors/PrintStructureVisitor.h"

TEST(NodeTest, DiskInitialization) {
    Disk disk("C:");
    EXPECT_EQ(disk.getName(), "C:");
}

TEST(NodeTest, DirectoryOperations) {
    Directory dir("Documents");
    auto file = std::make_shared<TextFile>("notes.txt", 100);
    dir.addChild(file);

    CalculateSizeVisitor visitor;
    dir.accept(visitor);
    EXPECT_EQ(visitor.getTotalSize(), 100);
}

TEST(NodeTest, FileSizeOperations) {
    TextFile textFile("document.txt", 500);
    ImageFile imageFile("photo.jpg", 1500);

    EXPECT_EQ(textFile.getSize(), 500);
    EXPECT_EQ(imageFile.getSize(), 1500);
}

TEST(NodeTest, VisitorTextFile) {
    TextFile file("test.txt", 200);
    CalculateSizeVisitor sizeVisitor;
    file.accept(sizeVisitor);
    EXPECT_EQ(sizeVisitor.getTotalSize(), 200);
}

TEST(NodeTest, VisitorImageFile) {
    ImageFile file("image.png", 800);
    CalculateSizeVisitor sizeVisitor;
    file.accept(sizeVisitor);
    EXPECT_EQ(sizeVisitor.getTotalSize(), 800);
}

TEST(NodeTest, PrintVisitor) {
    Disk disk("D:");
    Directory dir("Data");
    TextFile file("data.txt", 300);

    dir.addChild(std::make_shared<TextFile>(file));
    disk.addChild(std::make_shared<Directory>(dir));

    testing::internal::CaptureStdout();
    PrintStructureVisitor visitor;
    disk.accept(visitor);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("D:") != std::string::npos);
    EXPECT_TRUE(output.find("Data") != std::string::npos);
    EXPECT_TRUE(output.find("data.txt") != std::string::npos);
}