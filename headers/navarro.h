#ifndef NAVARRO_H
#define NAVARRO_H

#include <vector>
#include <unordered_map>
#include <string>
#include "Node.h"  // Assuming Node.h is in the same directory

int navarro(const std::vector<Node*>& graph, const std::unordered_map<int, Node*>& graphMap, const std::string& sequence);

#endif // NAVARRO_H
