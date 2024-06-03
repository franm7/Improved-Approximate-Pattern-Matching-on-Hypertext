#include "headers/navarro.h"

int navarro(const std::vector<Node*>& graph, const std::string& sequence) {
    std::vector<std::vector<int>> matrix(sequence.length() + 1, std::vector<int>(graph.size(), 0));
    
    for (size_t i = 1; i < sequence.length() + 1; i++){
        char curr = sequence[i - 1];
        int j = 0;
        for (Node* node : graph){     
            int id = node->getId();
            const std::vector<int>& predecessorIds = node->getPredecessors();
            int currValue = std::numeric_limits<int>::max();
            // if the nodes match
            if(curr == node ->getLetter()){
                // if there are predecessors
                if (!predecessorIds.empty()){
                    for(int predId : predecessorIds){
                        int value = matrix[i-1][predId-1];
                        if(value < currValue){
                            currValue = value;
                        }
                    }
                } else {                    
                    currValue = i - 1;
                }
            // if the nodes do not match
            } else {
                if (!predecessorIds.empty()){
                    for(int predId: predecessorIds){
                        int value = 1 + matrix[i-1][predId-1];                     
                        if(value < currValue){
                            currValue = value;

                        }
                        value = 1 + matrix[i][predId-1];
                        if(value < currValue){
                            currValue = value;

                        }
                    }
                } 
                if(matrix[i - 1][j] < currValue){
                    currValue = 1 + matrix[i - 1][j];
                }
            }   
            matrix[i][j] = currValue;
            ++j;
        }
    }
    int min = std::numeric_limits<int>::max();
    int i = sequence.length();
    for (size_t j = 0; j <graph.size(); j++){
        if(matrix[i][j] < min){
            min = matrix[i][j];
        }
    }
    return min;
}

int navarro_backtrack(const std::vector<Node*>& graph, const std::string& sequence) {
    std::vector<std::vector<MatrixElement>> matrix(sequence.length() + 1, std::vector<MatrixElement>(graph.size(), std::make_tuple(0, std::make_pair(-1, -1), -1)));

    for (size_t i = 1; i < sequence.length() + 1; i++) {
        char curr = sequence[i - 1];
        int j = 0;
        for (Node* node : graph) {
            int id = node->getId();
            const std::vector<int>& predecessorIds = node->getPredecessors();
            int currValue = std::numeric_limits<int>::max();
            std::pair<int, int> pred = std::make_pair(-1, -1); // Coordinates of the predecessor
            int operation = -1; // operation: -1 (B), 0 (M), 1 (I), 2 (m), 3(D)

            // if the nodes match
            if (curr == node->getLetter()) {
                operation = 0; // M
                // if there are predecessors
                if (!predecessorIds.empty()) {
                    for (int predId : predecessorIds) {
                        int value = std::get<0>(matrix[i-1][predId-1]);
                        if (value < currValue) {
                            currValue = value;
                            pred = std::make_pair(i - 1, predId - 1);
                        }
                    }
                } else {                    
                    currValue = i - 1;
                    pred = std::make_pair(-1, -1);
                }
            // if the nodes do not match
            } else {
                operation = 2; // M
                if (!predecessorIds.empty()) {
                    for (int predId : predecessorIds) {
                        int value = 1 + std::get<0>(matrix[i-1][predId-1]);                    
                        if (value < currValue) {
                            currValue = value;
                            pred = std::make_pair(i - 1, predId - 1);
                        }
                        value = 1 + std::get<0>(matrix[i][predId-1]);
                        if (value < currValue) {
                            currValue = value;
                            pred = std::make_pair(i, predId - 1);
                        }                        
                    }
                } 
                if (std::get<0>(matrix[i - 1][j]) < currValue) {
                    currValue = 1 + std::get<0>(matrix[i - 1][j]);
                    pred = std::make_pair(i - 1, j);
                }

                if (pred.first == i && pred.second == j - 1) {
                operation = 1; // I
                } else if (pred.first == i - 1 && pred.second == j) {
                    operation = 3; // D
                }
            }
            matrix[i][j] = std::make_tuple(currValue, pred, operation);
            ++j;
        }
    }

    // get min value in last row
    int min = std::numeric_limits<int>::max();
    int i = sequence.length();
    std::pair<int, int> min_i_and_j = std::make_pair(-1, -1);
    for (size_t j = 0; j < graph.size(); j++) {
        if (std::get<0>(matrix[i][j]) < min) {
            min = std::get<0>(matrix[i][j]);
            min_i_and_j = std::make_pair(i, j);
        }
    }

    backtrack(matrix, min_i_and_j, graph, sequence);

    return min;
}

void backtrack(const std::vector<std::vector<MatrixElement>>& matrix, const std::pair<int, int>& min_i_and_j, const std::vector<Node*>& graph, const std::string& sequence) {
    // for (const auto& row : matrix) {
    //     for (const auto& element : row) {
    //         std::cout << "(" << std::get<0>(element) << ",[" << std::get<1>(element).first << "," << std::get<1>(element).second << "]," << std::get<2>(element) << ") ";
    //     }
    //     std::cout << std::endl;
    // }
    
    auto [i, j] = min_i_and_j;
    std::vector<int> operations;
    std::string text_result;
    std::string sequence_result;

     while (i != -1 && j != -1) {
        auto [value, pred, op] = matrix[i][j];

        // Skip the base case operation
        if (op != -1) {
            operations.insert(operations.begin(), op);

            if (op == 0 || op == 2) { // Match or Mismatch
                text_result.insert(text_result.begin(), graph[j]->getLetter());
                sequence_result.insert(sequence_result.begin(), sequence[i - 1]);
            } else if (op == 1) { // Insertion in sequence
                text_result.insert(text_result.begin(), graph[j]->getLetter());
                sequence_result.insert(sequence_result.begin(), '-');
            } 
            // add this when you implement deletion
            else if (op == 3) { // Deletion in text?
                text_result.insert(text_result.begin(), '-');
                sequence_result.insert(sequence_result.begin(), sequence[i - 1]);
            }
        }

        std::tie(i, j) = pred;
    }

    std::cout << text_result << std::endl;
    // print operations
    for (int op : operations) {
        switch (op) {
            case 0:
                std::cout << "M";
                break;
            case 1:
                std::cout << "I";
                break;
            case 2:
                std::cout << "m";
                break;
            case 3:
                std::cout << "D";
                break;
        }
    }
    std::cout << std::endl;

    std::cout << sequence_result << std::endl;
}