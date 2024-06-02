#ifndef DATALOADER_H
#define DATALOADER_H

#include <vector>
#include <unordered_map>
#include <utility>
#include <string>
#include "Node.h"

// Function to load a Graph and GraphMap from a .gfa file
std::vector<Node*> loadGfa(const std::string& fileName);
// Line parsers for .gfa files
void parseSegmentLine(const std::string& line, std::vector<Node*>& graph, std::unordered_map<int, std::pair<Node*, Node*>> &sequenceMap);
void parseLinkLine(const std::string& line, std::vector<Node*>& graph, std::unordered_map<int, std::pair<Node*, Node*>> &sequenceMap);
// Function to load sequence lines from a .fastq file
std::vector<std::string> loadFastq(const std::string& fileName);

#endif // DATALOADER_H