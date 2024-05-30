#include "headers/Node.h"

int main() {
    // Example usage
    Node node1(1, 'A');
    Node node2(2, 'C');
    Node node3(3, 'G');

    node2.addPredecessor(&node1);
    node3.addPredecessor(&node1);
    node3.addPredecessor(&node2);

    node1.printNode();
    node2.printNode();
    node3.printNode();

    return 0;
}
