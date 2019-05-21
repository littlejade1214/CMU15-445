//===----------------------------------------------------------------------===//
//
//                         CMU-DB Project (15-445/645)
//                         ***DO NO SHARE PUBLICLY***
//
// Identification: src/concurrency/lock_manager.cpp
//
// Copyright (c) 2018, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "concurrency/lock_manager.h"
#include "assert.h"

namespace cmudb {

bool LockManager::LockShared(Transaction *txn, const RID &rid) { return false; }

bool LockManager::LockExclusive(Transaction *txn, const RID &rid) {
  return false;
}

bool LockManager::LockUpgrade(Transaction *txn, const RID &rid) {
  return false;
}

bool LockManager::Unlock(Transaction *txn, const RID &rid) { return false; }

void LockManager::AddEdge(txn_id_t t1, txn_id_t t2) {
  assert(Detection());
  return;
}

void LockManager::RemoveEdge(txn_id_t t1, txn_id_t t2) {
  assert(Detection());
  return;
}

bool LockManager::HasCycle(txn_id_t &txn_id) {
  assert(Detection());
  return false;
}

std::vector<std::pair<txn_id_t, txn_id_t>> LockManager::GetEdgeList() {
  assert(Detection());
  return {};
}

void LockManager::RunCycleDetection() {
  assert(Detection());
  while (enable_cycle_detection_) {
    // Sleep
    std::this_thread::sleep_for(CYCLE_DETECTION_INTERVAL);
    {
      std::unique_lock<std::mutex> l(latch_);
      continue;
      // Delete above continue and add your cycle detection and abort code here
    }
  }
}

} // namespace cmudb
