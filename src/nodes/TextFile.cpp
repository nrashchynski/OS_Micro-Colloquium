#include "nodes/TextFile.h"
#include "visitors/Visitor.h"

TextFile::TextFile(const std::string& name, size_t size)
    : FileSystemNode(name), size(size) {}

size_t TextFile::getSize() const {
    return size;
}

void TextFile::accept(Visitor& visitor) {
    visitor.visit(*this);
}