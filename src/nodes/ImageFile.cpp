#include "nodes/ImageFile.h"
#include "visitors/Visitor.h"

ImageFile::ImageFile(const std::string& name, size_t size)
    : FileSystemNode(name), size(size) {}

size_t ImageFile::getSize() const {
    return size;
}

void ImageFile::accept(Visitor& visitor) {
    visitor.visit(*this);
}