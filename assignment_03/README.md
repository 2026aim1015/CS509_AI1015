# Assignment 03

## Minimum Spanning Tree

### Objective

The objective of this assignment is to implement Minimum Spanning Tree (MST)
algorithms on weighted graphs using CSR representation.

The following algorithms are implemented:

- Prim's Algorithm
- Kruskal's Algorithm

The algorithms are tested on graphs of different sizes and their execution
times are measured.

## CSR Representation

The graph is stored using Compressed Sparse Row (CSR) representation.

The CSR structure contains:

- row_ptr
- col_ind
- weights

The input graph is read and converted into CSR before running the MST
algorithms.

## Prim's Algorithm

Prim's algorithm starts from a source vertex and builds the MST by repeatedly
selecting the minimum-weight edge that connects a vertex already in the MST
to a vertex outside the MST.

A priority queue is used to select the minimum-weight edge.

Time Complexity: O(E log V)

## Kruskal's Algorithm

Kruskal's algorithm considers the edges in increasing order of their weights.
An edge is added to the MST if it does not form a cycle.

Disjoint Set Union (DSU) is used for cycle detection.

Time Complexity: O(E log E)

## Folder Structure
```
assignment_03/
|
|-- include/
|   |-- graph.h
|   |-- mst.h
|
|-- src/
|   |-- csr.cpp
|   |-- mst.cpp
|
|-- driver/
|   |-- driver_prim.cpp
|   |-- driver_kruskal.cpp
|
|-- tests/
|   |-- mst_10.txt
|   |-- mst_100.txt
|   |-- mst_1000.txt
|   |-- mst_10000.txt
|   |-- mst_50000.txt
|   |-- mst_100000.txt
|
|-- outputs/
|   |-- prim/
|   |-- kruskal/
|
|-- README.md
```
## Source Files

csr.cpp:
Reads the input graph and creates the CSR representation.

mst.cpp:
Contains the implementation of Prim's and Kruskal's MST algorithms.

graph.h:
Defines the CSR graph structure.

mst.h:
Contains the declarations required by the MST implementation.

## Driver Files

driver_prim.cpp:
Loads the graph, runs Prim's algorithm, calculates the MST weight and
measures execution time.

driver_kruskal.cpp:
Loads the graph, runs Kruskal's algorithm, calculates the MST weight and
measures execution time.

## Test Cases

The following graph sizes were tested:
```
10
100
1,000
10,000
50,000
100,000
```
The larger test cases are used to observe the performance of the algorithms
as the number of vertices and edges increases.

## Compilation and Execution

### Prim

Compile:

g++ -std=c++17 src/csr.cpp src/mst.cpp driver/driver_prim.cpp -o prim_test

Run:

.\prim_test tests/mst_10.txt

Example:

.\prim_test tests/mst_10000.txt

### Kruskal

Compile:

g++ -std=c++17 src/csr.cpp src/mst.cpp driver/driver_kruskal.cpp -o kruskal_test

Run:

.\kruskal_test tests/mst_10.txt

Example:

.\kruskal_test tests/mst_10000.txt

## Results
```
Test File       Vertices    MST Weight       Kruskal Time (ms)    Prim Time (ms)
mst_10.txt      10          367               4.418                0
mst_100.txt     100         345               0                    0
mst_1000.txt    1,000       22523             0                    0.997
mst_10000.txt   10,000      198816            2.008                4.977
mst_50000.txt   50,000      1.88858e+006      6.994                -
mst_100000.txt  100,000     3.68632e+006      22.563               39.074
```

The MST weights obtained by Prim's and Kruskal's algorithms match for the
tested graphs. The execution time increases as the graph size increases.

## Saving Output

The console output can be saved in the output folders using PowerShell.

For Prim:

.\prim_test tests/mst_10.txt | Tee-Object outputs/prim/mst_10_output.txt

For Kruskal:

.\kruskal_test tests/mst_10.txt | Tee-Object outputs/kruskal/mst_10_output.txt

## Complexity
```
Algorithm       Time Complexity    Space Complexity
Prim's          O(E log V)         O(V + E)
Kruskal's       O(E log E)        O(V + E)
```
## Conclusion

Prim's and Kruskal's algorithms were implemented using CSR representation.
Both algorithms produce the same MST weight for the tested graphs.

The test results show that both algorithms work correctly on small as well
as large sparse graphs. The execution time increases with graph size, which
can be observed from the larger test cases.