#pragma once
#include "FileSystemNode.h"
#include <vector>
#include <memory>

class Visitor;

class Directory : public FileSystemNode {
public:
    explicit Directory(const std::string& name);
    void addChild(std::shared_ptr<FileSystemNode> child);
    void accept(Visitor& visitor) override;

private:
    std::vector<std::shared_ptr<FileSystemNode>> children;
};