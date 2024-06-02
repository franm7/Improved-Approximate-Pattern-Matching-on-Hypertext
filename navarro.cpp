#include "headers/navarro.h"

// Function definition
int navarro(const std::vector<Node*>& graph, const std::string& sequence) {
    int counter = 1;

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
                    
                    currValue = counter - 1;

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
        ++counter;

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

/*
int main() {
    // Example usage
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

    std::string sequence = "ACGTA";

    int result = navarro(graph, sequence);

    std::cout << "Navarro result: " << result << std::endl;

    for (Node* node : graph) {
        delete node;
    }

    return 0;
}
*/