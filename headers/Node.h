#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include <limits>

class Node {
public:
    // Constructor
    Node(int id, char letter);

    // Getter for the letter
    char getLetter() const;

    // Getter for the id
    int getId() const;

    // Add a predecessor
    void addPredecessor(Node* predecessor);

    // Get the list of predecessors
    const std::vector<Node*>& getPredecessors() const;

    // Print node information
    void printNode() const;

    // Getter for the value
    int getValue() const;

    // Setter for the value
    void setValue(int value);

private:
    int id;
    char letter;
    int value;
    std::vector<Node*> predecessors;
};

#endif // NODE_H
