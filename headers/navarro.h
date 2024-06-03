#ifndef NAVARRO_H
#define NAVARRO_H

#include <vector>
#include <unordered_map>
#include <string>
#include <tuple>
#include "Node.h"  // Assuming Node.h is in the same directory


using MatrixElement = std::tuple<int, std::pair<int, int>, int>; // (value, (predecessor_i, predecessor_j), operation)

int navarro(const std::vector<Node*>& graph, const std::string& sequence);
int navarro_backtrack(const std::vector<Node*>& graph, const std::string& sequence);
void backtrack(const std::vector<std::vector<MatrixElement>>& matrix, const std::pair<int, int>& min_i_and_j, const std::vector<Node*>& graph, const std::string& sequence);

#endif // NAVARRO_H
