# Improved-Approximate-Pattern-Matching-on-Hypertext
Project for "Bioinformatics 1"

https://www.fer.unizg.hr/predmet/bio1


## Navarro's algorithm

The goal is to implement Navarro's algorithm described in the paper (Improved approximate pattern matching on hypertext)

https://www.sciencedirect.com/science/article/pii/S0304397599003333

and compare it with Bit-parallel sequence-to-graph alignment algorithm described in the paper 

https://academic.oup.com/bioinformatics/article/35/19/3599/5372677%20%C2%A0

Algorithms need to be compared on the 3 kinds of topologies, as described in chapter 6.2 Graph topology experiment. It need not be compared on topologies that include cycles. Scripts that generate the test data are available at

https://github.com/maickrau/GraphAligner/tree/PaperExperiments/WabiExperimentSnake

## Running the Code

### For Ubuntu

1. Compile the code:
    ```bash
    g++ -g -o main main.cpp navarro.cpp Node.cpp dataloader.cpp
    ```

2. Run the compiled program:
    ```bash
    ./main <path_to_gfa> <path_to_fastq>
    ```
