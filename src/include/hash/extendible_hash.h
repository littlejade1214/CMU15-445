/*
 * extendible_hash.h : implementation of in-memory hash table using extendible
 * hashing
 *
 * Functionality: The buffer pool manager must maintain a page table to be able
 * to quickly map a PageId to its corresponding memory location; or alternately
 * report that the PageId does not match any currently-buffered page.
 */

#pragma once

#include <cstdlib>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include "hash/hash_table.h"

namespace cmudb {

// only support unique key
template <typename K, typename V>
class ExtendibleHash : public HashTable<K, V> {
  struct Bucket {
    Bucket() = default;
    explicit Bucket(size_t i, int d) : id(i), depth(d) {}
    std::map<K, V> items;          // key-value pairs
    size_t id = 0;                 // id of Bucket
    int depth = 0;                 // local depth counter
  };
public:
    // constructor
    ExtendibleHash(size_t size);

    // helper function to generate hash addressing
    size_t HashKey(const K &key);

    bool Find(const K &key, V &value);

    void Insert(const K &key, const V &value);

    bool Remove(const K &key);

    size_t Size() const { return pair_count_; }

    // helper function to get global depth
    int GetGlobalDepth() const;

    // helper function to get local depth
    int GetLocalDepth(int bucket_id) const;

    int GetNumBuckets() const;

private:
    mutable std::mutex mutex_;      // to protect shared data structure

    const size_t bucket_size_;    // largest number of elements in a bucket

    int bucket_count_;   // number of buckets in use

    size_t pair_count_;     // number of key-value pairs in table

    int depth;              // global depth

    std::vector<std::shared_ptr<Bucket>> bucket_;    // smart pointer for auto memory management
    std::shared_ptr<Bucket> split(std::shared_ptr<Bucket> &); // split the new bucket
};

} // namespace cmudb
