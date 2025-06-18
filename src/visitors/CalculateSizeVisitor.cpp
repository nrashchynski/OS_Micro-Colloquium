#include "CalculateSizeVisitor.h"
#include "../nodes/Disk.h"
#include "../nodes/Directory.h"
#include "../nodes/TextFile.h"
#include "../nodes/ImageFile.h"

size_t CalculateSizeVisitor::totalSize = 0;

void CalculateSizeVisitor::visit(Disk& disk) {
    totalSize = 0;
}

void CalculateSizeVisitor::visit(Directory& dir) {
}

void CalculateSizeVisitor::visit(TextFile& file) {
    totalSize += file.getSize();
}

void CalculateSizeVisitor::visit(ImageFile& file) {
    totalSize += file.getSize();
}

size_t CalculateSizeVisitor::getTotalSize() const {
    return totalSize;
}