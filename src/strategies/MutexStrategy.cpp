#include "MutexStrategy.h"

void MutexStrategy::lock() {
    mtx.lock();
}

void MutexStrategy::unlock() {
    mtx.unlock();
}