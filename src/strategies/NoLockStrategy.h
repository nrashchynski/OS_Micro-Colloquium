#pragma once
#include "SyncStrategy.h"

class NoLockStrategy : public SyncStrategy {
public:
    void lock() override;
    void unlock() override;
};