#include "nodes/Directory.h"
#include "visitors/Visitor.h"

Directory::Directory(const std::string& name) : FileSystemNode(name) {}

void Directory::addChild(std::shared_ptr<FileSystemNode> child) {
    children.push_back(child);
}

void Directory::accept(Visitor& visitor) {
    visitor.visit(*this);
    for (auto& child : children) {
        child->accept(visitor);
    }
}