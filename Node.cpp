#include "headers/Node.h"

// Constructor
Node::Node(int id, char letter) : id(id), letter(letter), value(0), previousValue(0) {}

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

// Getter for the value
int Node::getValue() const {
    return value;
}

// Setter for the value
void Node::setValue(int value) {
    this->value = value;
}

// Getter for the previous value
int Node::getPreviousValue() const {
    return previousValue;
}

// Setter for the previous value
void Node::setPreviousValue(int value) {
    this->previousValue = value;
}

// Print node information
void Node::printNode() const {
    std::cout << "Node ID: " << id << ", Letter: " << letter << ", Value: " << value << ", Predecessors: ";
    for (const auto& predId : predecessorIds) {
        std::cout << predId << " ";
    }
    std::cout << std::endl;
}
