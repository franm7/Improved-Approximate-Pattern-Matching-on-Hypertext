#include "headers/Node.h"
#include "headers/navarro.h"

int main() {
    // Dynamically allocate nodes
    Node* node1 = new Node(1, 'A');
    Node* node2 = new Node(2, 'C');
    Node* node3 = new Node(3, 'G');
    Node* node4 = new Node(4, 'T');
    Node* node5 = new Node(5, 'A');
    Node* node6 = new Node(6, 'G');
    Node* node7 = new Node(7, 'C');
    Node* node8 = new Node(8, 'T');
    Node* node9 = new Node(9, 'G');
    Node* node10 = new Node(10, 'G');

    // Add predecessors
    node3->addPredecessor(1);
    node3->addPredecessor(2);
    node4->addPredecessor(1);
    node4->addPredecessor(2);
    node5->addPredecessor(3);
    node5->addPredecessor(4);
    node6->addPredecessor(3);
    node6->addPredecessor(4);
    node7->addPredecessor(5);
    node7->addPredecessor(6);
    node8->addPredecessor(5);
    node8->addPredecessor(6);
    node9->addPredecessor(7);
    node9->addPredecessor(8);
    node10->addPredecessor(7);
    node10->addPredecessor(8);

    std::vector<Node*> graph = {node1, node2, node3, node4, node5, node6, node7, node8, node9, node10};

    std::unordered_map<int, Node*> graphMap;
    for (Node* node : graph) {
        graphMap[node->getId()] = node;
    }

    std::string sequence = "ACGTA";
    
    int result = navarro(graph, graphMap, sequence);

    std::cout << "Navarro result: " << result << std::endl;

    for (Node* node : graph) {
            delete node;
        }

    return 0;
}
