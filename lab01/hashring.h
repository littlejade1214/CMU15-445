#ifndef HASHRING_H
#define HASHRING_H

template <class Node, class Data, class Hash>
class HashRing {

public:
    typedef std::map<size_t, Node> NodeMap;
    HashRing(unsigned int numofreplicas);
    HashRing(unsigned int numofreplicas, const Hash& hash);

    size_t add(const Node& node);
    void remove(const Node& node);
    const Node& get(const Data& data);

private:
    NodeMap hashRing;
    const unsigned int replicas;
    const Hash hashFunction;
}

