# CS509 – PG Software Lab

## Assignment 04 – Vertex Coloring and PageRank

### Objective

This assignment implements two graph algorithms:

1. Greedy Vertex Coloring
2. PageRank

The programs are tested on graphs of different sizes to check correctness and execution time.

---

## Algorithms

### 1. Greedy Vertex Coloring

Greedy Vertex Coloring assigns a color to every vertex such that two adjacent vertices do not have the same color.

The algorithm processes the vertices one by one. For each vertex, it checks the colors already assigned to its adjacent vertices and selects the smallest available color.

The implementation also checks whether the final coloring is valid.

### 2. PageRank

PageRank calculates the importance of each vertex in a directed graph.

The algorithm starts with an initial rank for every vertex and repeatedly updates the ranks using the damping factor. The process continues until the change in rank becomes smaller than the given tolerance or the maximum number of iterations is reached.

The sum of PageRank values is also calculated to verify the result.

---

## CSR Representation

The graph used for Vertex Coloring is stored using Compressed Sparse Row (CSR) representation.

CSR uses two main arrays:

* `row_ptr` – stores the starting position of the adjacency list of each vertex.
* `col_ind` – stores the adjacent vertices.

CSR provides a compact representation of sparse graphs and allows efficient traversal of graph edges.

---

## Folder Structure

```text
assignment_04/
│
├── README.md
│
├── include/
│   ├── graph.h
│   ├── vertex_coloring.h
│   └── vertex_pagerank.h
│
├── src/
│   ├── csr.cpp
│   ├── vertex_coloring.cpp
│   └── vertex_pagerank.cpp
│
├── driver/
│   ├── vertex_coloring_driver.cpp
│   └── vertex_pagerank_driver.cpp
│
├── tests/
│   ├── vertex_coloring/
│   │   ├── color_10.txt
│   │   ├── color_100.txt
│   │   ├── color_10000.txt
│   │   ├── color_50000.txt
│   │   └── color_100000.txt
│   │
│   └── vertex_pagerank/
│       ├── pr_10.txt
│       ├── pr_100.txt
│       ├── pr_1000.txt
│       ├── pr_10000.txt
│       └── pr_50000.txt
│
└── outputs/
    ├── vertex_coloring/
    │   ├── color_10_output.txt
    │   ├── color_100_output.txt
    │   ├── color_10000_output.txt
    │   ├── color_50000_output.txt
    │   └── color_100000_output.txt
    │
    └── vertex_pagerank/
        ├── pr_10_output.txt
        ├── pr_100_output.txt
        ├── pr_1000_output.txt
        ├── pr_10000_output.txt
        └── pr_50000_output.txt
```

---

## Source Files

### `src/csr.cpp`

This file loads the graph input and converts the graph into CSR representation.

### `src/vertex_coloring.cpp`

This file contains the Greedy Vertex Coloring algorithm.

It assigns colors to the vertices and checks that no two adjacent vertices have the same color.

### `src/vertex_pagerank.cpp`

This file contains the PageRank algorithm.

It calculates the rank of each vertex iteratively and checks whether the algorithm has converged.

---

## Driver Files

### `driver/vertex_coloring_driver.cpp`

The Vertex Coloring driver:

* reads the input file
* loads the graph
* runs Greedy Vertex Coloring
* prints the color assigned to each vertex
* prints the number of colors used
* measures execution time

### `driver/vertex_pagerank_driver.cpp`

The PageRank driver:

* reads the graph
* reads PageRank parameters
* runs the PageRank algorithm
* prints the rank of each vertex
* prints the sum of ranks
* prints the number of iterations
* displays the convergence status
* measures execution time

---

## Test Cases

### Vertex Coloring

```text
color_10.txt
color_100.txt
color_10000.txt
color_50000.txt
color_100000.txt
```

### PageRank

```text
pr_10.txt
pr_100.txt
pr_1000.txt
pr_10000.txt
pr_50000.txt
```

---

## Compilation and Execution

### Vertex Coloring

Go to the Assignment 4 directory:

```bash
cd assignment_04
```

Compile:

```bash
g++ -std=c++17 -O2 src/csr.cpp src/vertex_coloring.cpp driver/vertex_coloring_driver.cpp -o vertex_coloring
```

Run:

```bash
./vertex_coloring tests/vertex_coloring/color_10.txt
```

For other test files:

```bash
./vertex_coloring tests/vertex_coloring/color_100.txt
```

```bash
./vertex_coloring tests/vertex_coloring/color_10000.txt
```

---

### PageRank

Compile:

```bash
g++ -std=c++17 -O2 src/vertex_pagerank.cpp driver/vertex_pagerank_driver.cpp -o vertex_pagerank
```

Run:

```bash
./vertex_pagerank tests/vertex_pagerank/pr_10.txt
```

For other test files:

```bash
./vertex_pagerank tests/vertex_pagerank/pr_100.txt
```

```bash
./vertex_pagerank tests/vertex_pagerank/pr_1000.txt
```

---

# Results

## Vertex Coloring Results

| Test File          | Vertices | Colors Used | Execution Time (ms) |
| ------------------ | -------: | ----------: | ------------------: |
| `color_10.txt`     |       10 |           2 |              0.0016 |
| `color_100.txt`    |      100 |           7 |              0.0319 |
| `color_10000.txt`  |   10,000 |          14 |                6.81 |
| `color_50000.txt`  |   50,000 |          14 |             32.4575 |
| `color_100000.txt` |  100,000 |          15 |             64.5574 |

The coloring was successfully generated for all test cases. The number of colors used was between 2 and 15 for the tested graphs.

The execution time increased with the graph size.

---

## PageRank Results

| Test File      | Vertices | Iterations | Rank Sum | Converged | Execution Time (ms) |
| -------------- | -------: | ---------: | -------: | --------- | ------------------: |
| `pr_10.txt`    |       10 |          1 | 1.000000 | true      |            0.004400 |
| `pr_100.txt`   |      100 |         14 | 1.000000 | true      |            0.284600 |
| `pr_1000.txt`  |    1,000 |         11 | 1.000000 | true      |            1.327700 |
| `pr_10000.txt` |   10,000 |         11 | 1.000000 | true      |           13.566098 |
| `pr_50000.txt` |   50,000 |         11 | 1.000000 | true      |           67.410991 |

All PageRank test cases converged successfully. The sum of ranks was `1.000000` for all the tested graphs.

---

## Common Wrapper

Assignment 4 can also be accessed through the common wrapper used for the repository.

From the repository root, compile the Vertex Coloring program:

```bash
cd assignment_04
g++ -std=c++17 -O2 src/csr.cpp src/vertex_coloring.cpp driver/vertex_coloring_driver.cpp -o vertex_coloring
```

Compile PageRank:

```bash
g++ -std=c++17 -O2 src/vertex_pagerank.cpp driver/vertex_pagerank_driver.cpp -o vertex_pagerank
```

Return to the repository root:

```bash
cd ..
```

Compile the common wrapper:

```bash
g++ -std=c++17 common_wrapper/wrapper.cpp -o common_wrapper/wrapper
```

Run the wrapper:

```bash
./common_wrapper/wrapper
```

The wrapper provides the option to select Assignment 4 and run Vertex Coloring or PageRank test cases.

---

## Output Files

The generated Vertex Coloring outputs are stored in:

```text
outputs/vertex_coloring/
```

The generated PageRank outputs are stored in:

```text
outputs/vertex_pagerank/
```

Each output file contains the algorithm result and execution time.

---

## Complexity

### Greedy Vertex Coloring

The graph is stored in CSR form, requiring:

```text
O(V + E)
```

space for the graph representation.

The coloring algorithm traverses the adjacency lists of the vertices. The additional arrays used for coloring require `O(V)` space.

### PageRank

For one PageRank iteration, all vertices and edges are processed:

```text
O(V + E)
```

For `I` iterations, the total time complexity is:

```text
O(I(V + E))
```

The additional space used by the PageRank algorithm is:

```text
O(V)
```

apart from the CSR graph storage.

---

## Conclusion

Assignment 4 implements Greedy Vertex Coloring and PageRank and tests them on graphs of different sizes.

The Vertex Coloring algorithm successfully produced valid color assignments for all the provided test cases. PageRank converged for all tested graphs, with the sum of ranks equal to `1.000000`.

The execution times increase as the graph size increases, showing the effect of graph size on the running time of both algorithms.
