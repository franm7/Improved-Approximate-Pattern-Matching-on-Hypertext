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
    
    std::vector<Node*> graph = {};
    std::unordered_map<int, Node*> graphMap;
    std::tie(graph, graphMap) = loadGfa(gfaFilePath);
    std::vector<std::string> sequences = loadFastq(fastqFilePath);
    int cnt = 0;
    std::vector<int> results;
    for (std::string& sequence : sequences) {
        // std::cout << "Sequence: " << sequence << std::endl;
        int result = navarro(graph, graphMap, sequence);
        results.push_back(result);
        // if (cnt > 3) {
        //     break;
        // }
        // cnt++;
        // std::cout << "Navarro result: " << result << std::endl;
    }
    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << "Sequence " << i + 1 << ": " << results[i] << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    for (Node* node : graph) {
            delete node;
        }

    return 0;
}
