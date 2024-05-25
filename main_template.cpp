#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"

int main(int argc, char **argv) {
    std::string gfaFilePath = argv[1];
    std::string fastqFilePath = argv[2];

    Graph* graph = Graph::loadFromFile(gfaFilePath);
    for (const auto &element : graph->vertices) {
        std::cout << element.first << std::endl; // prints keys of map
    }

    return 0;
}

// int main() {
//     // Create some nodes
//     Node node1(1, "ATCG");
//     Node node2(2, "CGTA");
//     Node node3(3, "GCAA");

//     // Create some edges
//     Edge edge1(1, 2, '+', '-', 10);
//     Edge edge2(2, 3, '-', '+', 15);

//     // Add edges to nodes
//     node1.outEdges.insert(edge1);
//     node2.inEdges.insert(edge1);
//     node2.outEdges.insert(edge2);
//     node3.inEdges.insert(edge2);

//     // Display nodes and their edges
//     std::cout << "Node 1 ID: " << node1.id << ", Sequence: " << node1.sequence << std::endl;
//     std::cout << "Node 1 Outgoing Edges:" << std::endl;
//     for (const auto& edge : node1.outEdges) {
//         std::cout << "    From: " << edge.from << ", To: " << edge.to << ", From Orient: " << edge.fromOrient << ", To Orient: " << edge.toOrient << ", Overlap: " << edge.overlap << std::endl;
//     }

//     std::cout << "Node 2 ID: " << node2.id << ", Sequence: " << node2.sequence << std::endl;
//     std::cout << "Node 2 Incoming Edges:" << std::endl;
//     for (const auto& edge : node2.inEdges) {
//         std::cout << "    From: " << edge.from << ", To: " << edge.to << ", From Orient: " << edge.fromOrient << ", To Orient: " << edge.toOrient << ", Overlap: " << edge.overlap << std::endl;
//     }
//     std::cout << "Node 2 Outgoing Edges:" << std::endl;
//     for (const auto& edge : node2.outEdges) {
//         std::cout << "    From: " << edge.from << ", To: " << edge.to << ", From Orient: " << edge.fromOrient << ", To Orient: " << edge.toOrient << ", Overlap: " << edge.overlap << std::endl;
//     }

//     std::cout << "Node 3 ID: " << node3.id << ", Sequence: " << node3.sequence << std::endl;
//     std::cout << "Node 3 Incoming Edges:" << std::endl;
//     for (const auto& edge : node3.inEdges) {
//         std::cout << "    From: " << edge.from << ", To: " << edge.to << ", From Orient: " << edge.fromOrient << ", To Orient: " << edge.toOrient << ", Overlap: " << edge.overlap << std::endl;
//     }

//     // Test equality operators
//     Node node4(1, "ATCG");
//     std::cout << "Are nodes 1 and 4 equal? " << (node1 == node4 ? "Yes" : "No") << std::endl;

//     Edge edge3(1, 2, '+', '-', 10);
//     std::cout << "Are edges 1 and 3 equal? " << (edge1 == edge3 ? "Yes" : "No") << std::endl;

//     return 0;
// }
