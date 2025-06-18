#pragma once
#include "FileSystemNode.h"
#include <vector>
#include <memory>

class Visitor;

class Disk : public FileSystemNode {
public:
    explicit Disk(const std::string& name);
    void addChild(std::shared_ptr<FileSystemNode> child);
    void accept(Visitor& visitor) override;

private:
    std::vector<std::shared_ptr<FileSystemNode>> children;
};