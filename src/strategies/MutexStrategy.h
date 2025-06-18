#pragma once
#include "SyncStrategy.h"
#include <mutex>

class MutexStrategy : public SyncStrategy {
public:
    void lock() override;
    void unlock() override;

private:
    std::mutex mtx;
};