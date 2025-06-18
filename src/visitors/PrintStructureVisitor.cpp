#include "PrintStructureVisitor.h"
#include "../nodes/Disk.h"
#include "../nodes/Directory.h"
#include "../nodes/TextFile.h"
#include "../nodes/ImageFile.h"
#include <iostream>

void PrintStructureVisitor::visit(Disk& disk) {
    std::cout << "[Disk] " << disk.getName() << std::endl;
}

void PrintStructureVisitor::visit(Directory& dir) {
    std::cout << "[Directory] " << dir.getName() << std::endl;
}

void PrintStructureVisitor::visit(TextFile& file) {
    std::cout << "[TextFile] " << file.getName() << std::endl;
}

void PrintStructureVisitor::visit(ImageFile& file) {
    std::cout << "[ImageFile] " << file.getName() << std::endl;
}