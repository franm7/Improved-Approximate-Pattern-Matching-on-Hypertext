// added by Adam
#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <string>
#include "Node.h"

class Graph {
public:
    std::unordered_map<int, Node> vertices;

    static Graph *loadFromFile(std::string fileName);
private:
    Graph();
    static void parseSegmentLine(const std::string& line, Graph* Graph);
    static void parseLinkLine(const std::string& line, Graph* Graph);
};

#endif 