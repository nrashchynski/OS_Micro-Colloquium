#pragma once

class SyncStrategy {
public:
    virtual ~SyncStrategy() = default;
    virtual void lock() = 0;
    virtual void unlock() = 0;
};