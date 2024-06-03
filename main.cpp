#include "headers/Node.h"
#include "headers/navarro.h"
#include "headers/dataloader.h"
#include <chrono>

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <gfa_file_path> <fastq_file_path>" << std::endl;
        return 1;
    }
    std::string gfaFilePath = argv[1];
    std::string fastqFilePath = argv[2];

    auto start = std::chrono::high_resolution_clock::now();
    
    std::vector<Node*> graph = loadGfa(gfaFilePath);
    std::vector<std::string> sequences = loadFastq(fastqFilePath);
    std::vector<int> min_edit_distances;
    for (std::string& sequence : sequences) {
        // std::cout << "Sequence: " << sequence << std::endl;
        // you can use navarro function if you don't want to backtrack
        int min_edit_distance = navarro_backtrack(graph, sequence);
        min_edit_distances.push_back(min_edit_distance);
        std::cout << "Minimal edit distance: " << min_edit_distance << std::endl;
    }

    std::cout << "Minimal distances by sequence:" << std::endl;
    for (size_t i = 0; i < min_edit_distances.size(); ++i) {
        std::cout << "Sequence " << i + 1 << ": " << min_edit_distances[i] << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    for (Node* node : graph) {
            delete node;
    }

    return 0;
}
