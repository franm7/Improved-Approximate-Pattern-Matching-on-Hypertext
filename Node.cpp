// added by Adam
#include "headers/Node.h"

Node::Node() = default;
Node::Node(int id, const std::string &sequence) : id{id}, sequence{sequence} {}

// operators

bool Node::operator==(const Node &rhs) const {
    return id == rhs.id;
}

bool Node::operator!=(const Node &rhs) const {
    return !(rhs == *this);
}