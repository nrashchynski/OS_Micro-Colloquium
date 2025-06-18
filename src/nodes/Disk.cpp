#include "nodes/Disk.h"
#include "visitors/Visitor.h"

Disk::Disk(const std::string& name) : FileSystemNode(name) {}

void Disk::addChild(std::shared_ptr<FileSystemNode> child) {
    children.push_back(child);
}

void Disk::accept(Visitor& visitor) {
    visitor.visit(*this);
    for (auto& child : children) {
        child->accept(visitor);
    }
}