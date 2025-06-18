#pragma once
#include "FileSystemNode.h"

class ImageFile : public FileSystemNode {
public:
    ImageFile(const std::string& name, size_t size);
    size_t getSize() const;
    void accept(Visitor& visitor) override;

private:
    size_t size;
};