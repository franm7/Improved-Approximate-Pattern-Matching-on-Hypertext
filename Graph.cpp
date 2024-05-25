// added by Adam
#include <sstream>
#include <fstream>
#include "Graph.h"

Graph::Graph() {}

void Graph::parseSegmentLine(const std::string& line, Graph* graph) {
    std::stringstream ss{line};
    std::string type; // always 'S', don't need it
    int id;
    std::string sequence;

    ss >> type >> id >> sequence;
    graph->vertices[id] = Node(id, sequence);
}

void Graph::parseLinkLine(const std::string& line, Graph* graph) {
    std::stringstream ss{line};
    std::string type; // always 'L', don't need it
    int from;
    int to;
    char fromOrient;
    char toOrient;
    int overlap;

    ss >> type >> from >> fromOrient >> to >> toOrient >> overlap;
    // add edges to both vertices
    graph->vertices[from].outEdges.insert(Edge(from, to, fromOrient, toOrient, overlap));
    graph->vertices[to].inEdges.insert(Edge(to, from, toOrient, fromOrient, overlap));
}

Graph* Graph::loadFromFile(const std::string fileName) {
    Graph* graph = new Graph();
    std::ifstream file{fileName};

    std::string line;
    while (std::getline(file, line)) {
        if (line[0] == 'S') {
            parseSegmentLine(line, graph);
        } else if (line[0] == 'L') {
            parseLinkLine(line, graph);
        }
    }

    return graph;
}