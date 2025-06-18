#pragma once
#include <memory>
#include "FileSystemNode.h"
#include "strategies/SyncStrategy.h"

template<typename TStrategy>
class ThreadSafeFileSystem {
public:
    explicit ThreadSafeFileSystem(std::shared_ptr<FileSystemNode> root);
    void performOperation(Visitor& visitor);

private:
    std::shared_ptr<FileSystemNode> root;
    TStrategy strategy;
};