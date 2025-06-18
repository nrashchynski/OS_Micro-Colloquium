#include "ThreadSafeFileSystem.h"

template<typename TStrategy>
ThreadSafeFileSystem<TStrategy>::ThreadSafeFileSystem(std::shared_ptr<FileSystemNode> root)
    : root(root) {}

template<typename TStrategy>
void ThreadSafeFileSystem<TStrategy>::performOperation(Visitor& visitor) {
    strategy.lock();
    root->accept(visitor);
    strategy.unlock();
}