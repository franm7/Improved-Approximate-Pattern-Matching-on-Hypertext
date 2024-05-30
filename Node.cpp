#include "headers/Node.h"

// Constructor
Node::Node(int id, char letter) : id(id), letter(letter), value(std::numeric_limits<int>::max()) {}

// Getter for the letter
char Node::getLetter() const {
    return letter;
}

// Getter for the id
int Node::getId() const {
    return id;
}

// Add a predecessor
void Node::addPredecessor(Node* predecessor) {
    predecessors.push_back(predecessor);
}

// Get the list of predecessors
const std::vector<Node*>& Node::getPredecessors() const {
    return predecessors;
}

// Getter for the value
int Node::getValue() const {
    return value;
}

// Setter for the value
void Node::setValue(int value) {
    this->value = value;
}

// Print node information
void Node::printNode() const {
    std::cout << "Node ID: " << id << ", Letter: " << letter << ", Value: " << value << ", Predecessors: ";
    for (const auto& pred : predecessors) {
        std::cout << pred->getId() << " ";
    }
    std::cout << std::endl;
}
