// added by Adam
#ifndef NODE_H
#define NODE_H

#include <string>
#include <unordered_set>
#include "Edge.h"

class Node {
public:
    int id = 0;
    std::string sequence = "";
    std::unordered_set<Edge> inEdges;
    std::unordered_set<Edge> outEdges;

    Node();
    Node(int id, const std::string &sequence);

    bool operator==(const Node &rhs) const;
    bool operator!=(const Node &rhs) const;
};

// hash function for Node class
namespace std {
    template<>
    struct hash<Node> {
        size_t operator()(const Node &x) const {
            return hash<long>()(x.id);
        }
    };
}

#endif