// added by Adam
#ifndef EDGE_H
#define EDGE_H

#include <functional>

class Edge {
public:
    int from;
    int to;
    char fromOrient;
    char toOrient;
    int overlap;

    Edge(int from, int to, char fromOrient, char toOrient, int overlap);
    bool operator==(const Edge &rhs) const;
    bool operator!=(const Edge &rhs) const;
};

// hash function for Edge class
namespace std {
    template<>
    struct hash<Edge> {
        size_t operator()(const Edge &x) const noexcept {
            size_t h1 = hash<int>()(x.from);
            size_t h2 = hash<int>()(x.to);
            size_t h3 = hash<char>()(x.fromOrient);
            size_t h4 = hash<char>()(x.toOrient);
            return h1 ^ h2 ^ h3 ^ h4;
        }
    };
}

#endif