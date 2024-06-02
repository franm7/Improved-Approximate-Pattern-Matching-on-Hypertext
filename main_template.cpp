#include "headers/Node.h"
#include "headers/navarro.h"

int main() {
    // twopath example
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

    //linear example
    Node* node11 = new Node(1, 'T');
    Node* node12 = new Node(2, 'C');
    Node* node13 = new Node(3, 'G');
    Node* node14 = new Node(4, 'G');
    Node* node15 = new Node(5, 'C');
    Node* node16 = new Node(6, 'A');
    Node* node17 = new Node(7, 'G');
    Node* node18 = new Node(8, 'C');

    node12->addPredecessor(1);
    node13->addPredecessor(2);
    node14->addPredecessor(3);
    node15->addPredecessor(4);
    node16->addPredecessor(5);
    node17->addPredecessor(6);
    node18->addPredecessor(7);

    std::vector<Node*> graph1 = {node11, node12, node13, node14, node15, node16, node17, node18};
    std::unordered_map<int, Node*> graphMap1;
    for (Node* node : graph1) {
        graphMap1[node->getId()] = node;
    }
    result = navarro(graph1, graphMap1, "CGAT");
    std::cout << "result: " << result << std::endl;


    for (Node* node : graph1) {
            delete node;
        }


    return 0;

    // g++ -g -o main main_template.cpp navarro.cpp Node.cpp
}
