# Assignment 02

## Bellman-Ford and Floyd-Warshall

## Objective

The objective of this assignment is to implement Bellman-Ford and Floyd-Warshall algorithms on weighted graphs using CSR representation.

Bellman-Ford is used to find the shortest path from a single source vertex.

Floyd-Warshall is used to find the shortest paths between all pairs of vertices.

Both algorithms include negative-cycle detection.

## Algorithms

### Bellman-Ford

Bellman-Ford finds the shortest distance from a source vertex to all other vertices. It also works with negative edge weights and can detect negative cycles.

**Time Complexity:** O(V × E)

### Floyd-Warshall

Floyd-Warshall finds the shortest distance between every pair of vertices.

**Time Complexity:** O(V³)

**Space Complexity:** O(V²)

## CSR Representation

The graph is stored using Compressed Sparse Row (CSR) representation.

The CSR structure contains:

- `row_ptr`
- `col_ind`
- `weights`

The input graph is read and converted into CSR before running the algorithms.

## Input Format

The input file follows this format:

```text
V E
vertex degree destination weight destination weight ...
...
SOURCE s
```

Example:

```text
5 10
0 2 1 6 3 7
1 3 2 5 3 8 4 -4
2 1 1 -2
3 2 2 -3 4 9
4 2 0 2 2 7
SOURCE 0
```

## Folder Structure

```text
assignment_02/
│
├── include/
│   ├── graph.h
│   ├── bellman_ford.h
│   └── floyd_warshall.h
│
├── src/
│   ├── csr.cpp
│   ├── bellman_ford.cpp
│   └── floyd_warshall.cpp
│
├── driver/
│   ├── driver_bellman_ford.cpp
│   └── driver_floyd_warshall.cpp
│
├── tests/
│   ├── bellman_ford/
│   │   ├── bf_10.txt
│   │   ├── bf_100.txt
│   │   ├── bf_10000.txt
│   │   ├── bf_50000.txt
│   │   ├── bf_100000.txt
│   │   └── bf_20.txt
│   │
│   └── floyd_warshall/
│       ├── fw_10.txt
│       ├── fw_100.txt
│       ├── fw_500.txt
│       ├── fw_1000.txt
│       ├── fw_2000.txt
│       └── fw_20.txt
│
└── outputs/
    ├── bellman_ford/
    │   ├── bf_10_output.txt
    │   ├── bf_100_output.txt
    │   ├── bf_10000_output.txt
    │   ├── bf_50000_output.txt
    │   ├── bf_100000_output.txt
    │   └── bf_20_output.txt
    │
    └── floyd_warshall/
        ├── fw_10_output.txt
        ├── fw_100_output.txt
        ├── fw_500_output.txt
        ├── fw_1000_output.txt
        ├── fw_2000_output.txt
        └── fw_20_output.txt
```

## Source Files

- `csr.cpp` - Reads the input graph and creates the CSR representation.
- `bellman_ford.cpp` - Bellman-Ford implementation.
- `floyd_warshall.cpp` - Floyd-Warshall implementation.

## Driver Files

- `driver_bellman_ford.cpp`
- `driver_floyd_warshall.cpp`

The test file name is given while running the program.

## Test Cases

### Bellman-Ford

The following graph sizes are used:

```text
10
100
10,000
50,000
100,000
```

The two largest graphs are sparse with approximately `2V` to `4V` edges.

A separate 20-vertex test is also used for negative-cycle detection.

### Floyd-Warshall

The following graph sizes are used:

```text
10
100
500
1,000
2,000
```

Larger graphs are not used because Floyd-Warshall requires O(V³) time and O(V²) memory.

A separate 20-vertex test is used for negative-cycle detection.

## Compilation and Execution

### Bellman-Ford

Compile:

```text
g++ -std=c++17 src/csr.cpp src/bellman_ford.cpp driver/driver_bellman_ford.cpp -o bellman_test
```

Run:

```text
.\bellman_test tests/bellman_ford/bf_10.txt
```

For example:

```text
.\bellman_test tests/bellman_ford/bf_10000.txt
```

### Floyd-Warshall

Compile:

```text
g++ -std=c++17 src/csr.cpp src/floyd_warshall.cpp driver/driver_floyd_warshall.cpp -o floyd_test
```

Run:

```text
.\floyd_test tests/floyd_warshall/fw_10.txt
```

For example:

```text
.\floyd_test tests/floyd_warshall/fw_2000.txt
```

## Output

The output contains the shortest distances or distance matrix, negative-cycle status, and execution time.

### Bellman-Ford Results

| Test File | Vertices | Edges | Negative Cycle | Execution Time (ms) |
|---|---:|---:|---|---:|
| `bf_10.txt` | 10 | 20 | None | 0 |
| `bf_100.txt` | 100 | 300 | Detected | 0 |
| `bf_10000.txt` | 10,000 | 30,000 | Detected | 7593.35 |
| `bf_50000.txt` | 50,000 | 150,000 | Detected | 215471 |
| `bf_100000.txt` | 100,000 | 300,000 | Detected | 879836 |

### Floyd-Warshall Results

| Test File | Vertices | Edges | Negative Cycle | Execution Time (ms) |
|---|---:|---:|---|---:|
| `fw_10.txt` | 10 | 20 | None | 0 |
| `fw_100.txt` | 100 | 300 | None | 10.979 |
| `fw_500.txt` | 500 | 1,500 | None | 1306.77 |
| `fw_1000.txt` | 1,000 | 3,000 | None | 10557 |
| `fw_2000.txt` | 2,000 | 6,000 | None | 84211.9 |

### Negative-Cycle Tests

| Test File | Vertices | Algorithm | Result | Execution Time (ms) |
|---|---:|---|---|---:|
| `bf_20_output.txt` | 20 | Bellman-Ford | Detected | 0 |
| `fw_20_output.txt` | 20 | Floyd-Warshall | Detected | 0 |

## Saving Output

The console output can be saved in the corresponding output folder using PowerShell.

For Bellman-Ford:

```text
.\bellman_test tests/bellman_ford/bf_10.txt | Tee-Object outputs/bellman_ford/bf_10_output.txt
```

For Floyd-Warshall:

```text
.\floyd_test tests/floyd_warshall/fw_10.txt | Tee-Object outputs/floyd_warshall/fw_10_output.txt
```

## Complexity

| Algorithm | Time Complexity | Space Complexity |
|---|---|---|
| Bellman-Ford | O(V × E) | O(V) |
| Floyd-Warshall | O(V³) | O(V²) |

## Conclusion

Bellman-Ford is suitable for single-source shortest paths and supports negative edge weights.

Floyd-Warshall calculates shortest paths between all pairs of vertices. Its execution time increases quickly with graph size because of its O(V³) complexity.
