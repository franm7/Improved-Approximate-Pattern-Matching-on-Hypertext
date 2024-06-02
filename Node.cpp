#include "headers/Node.h"

// Constructor
Node::Node(int id, char letter) : id(id), letter(letter) {}

// Getter for the letter
char Node::getLetter() const {
    return letter;
}

// Getter for the id
int Node::getId() const {
    return id;
}

// Add a predecessor
void Node::addPredecessor(int predecessorId) {
    predecessorIds.push_back(predecessorId);
}

// Get the list of predecessors
const std::vector<int>& Node::getPredecessors() const {
    return predecessorIds;
}


// Print node information
void Node::printNode() const {
    std::cout << "Node ID: " << id << ", Letter: " << letter << ", Predecessors: ";
    for (const auto& predId : predecessorIds) {
        std::cout << predId << " ";
    }
    std::cout << std::endl;
}
