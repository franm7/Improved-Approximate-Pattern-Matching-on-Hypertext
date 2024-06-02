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
    void addPredecessor(int predecessorId);

    // Get the list of predecessors
    const std::vector<int>& getPredecessors() const;

    // Print node information
    void printNode() const;


private:
    int id;
    char letter;
    std::vector<int> predecessorIds;
};

#endif // NODE_H
