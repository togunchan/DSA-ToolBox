# DSA Toolbox

A modular command-line application for practicing data structures and algorithms in C++.

This project aims to systematically implement, test, and benchmark classic data structures and algorithms in C++, following patterns and complexity seen in competitive programming platforms such as LeetCode.

---

## Features

- QuickSort algorithm
- MergeSort algorithm
- DFS (Depth-First Search) graph traversal
- Command-Line Interface (CLI) with modular subcommands
- File-based input handling (e.g., `.txt`)
- Benchmarking support:
  - Sorting algorithms: `benchmark-sort`
  - Graph algorithms: `benchmark-graph`

---

## Compilation

```bash
mkdir build
cd build
cmake ..
make
./dsa_toolbox
```

---

## Usage

### Sorting Algorithms
```bash
./dsa_toolbox sort --algo quicksort --input data/sample.txt
./dsa_toolbox sort --algo mergesort --input data/sample.txt
```

#### Sample `data/sample.txt` content:
```
9 4 7 3 1 6 2 5 8
```

---

## Sorting Benchmark
```bash
./dsa_toolbox benchmark-sort --input ../data/sample.txt
```

#### Example output:
```
QuickSort took: 14 microseconds
MergeSort took: 118 microseconds
```

---

## DFS Graph Traversal
```bash
./dsa_toolbox graph --algo dfs --input ../data/graph.txt
```

#### Sample `data/graph.txt` content:
```
5 6
0 1
0 2
1 3
1 4
2 4
3 4
```

#### Example output:
```
DFS traversal: 0 1 3 4 2
```

---

## Graph Benchmark
```bash
./dsa_toolbox benchmark-graph --input ../data/graph.txt
```

#### Example output:
```
Graph traversal took: 22 microseconds
```

---

## Project Structure

```
dsa-toolbox/
├── src/
│   ├── sort/
│   │   ├── quickSort.hpp
│   │   └── mergeSort.hpp
│   └── graph/
│       ├── graph.hpp
│       └── graph.cpp
├── utils/
│   └── input_parser.hpp
├── data/
│   ├── sample.txt
│   └── graph.txt
├── main.cpp
└── README.md
```

---

## Planned Features

### Advanced Algorithmic Expansions

#### 1. Heuristic & Optimization Algorithms
- Greedy Algorithms (Interval scheduling, Huffman coding)
- Dynamic Programming (Knapsack, LIS, Matrix Chain Multiplication)
- Backtracking (Sudoku solver, N-Queens)
- Branch and Bound (Traveling Salesman, 0/1 Knapsack upper bounds)

#### 2. Advanced Graph Algorithms
- Union-Find (Disjoint Set Union)
- Kruskal’s and Prim’s MST algorithms
- Tarjan’s Algorithm (SCC Detection)
- Floyd-Warshall, Johnson’s Algorithm (All Pairs Shortest Paths)

#### 3. Non-Trivial Data Structures
- Min/Max Heap
- Trie (Prefix tree)
- Segment Tree, Fenwick Tree (Binary Indexed Tree)
- LRU Cache (Doubly Linked List + Hashmap)
- Hash Table Implementation

#### 4. Expanded Testing & Benchmarking Framework
- Test runner CLI → `./dsa_toolbox test`
- Test case randomizer/generator
- JSON-based test scenarios (`tests/cases/*.json`)
- Performance regression alerts

#### 5. Flexible Input/Output Support
- **YAML or JSON Configuration Example:**
  ```yaml
  algorithm: mergesort
  input_file: data/sample.txt
  mode: benchmark
  ```

- **Standard input execution:**
  ```bash
  echo "4 2 6 1" | ./dsa_toolbox sort --algo quicksort
  ```

#### 6. CLI UX Improvements
- Automatic `--help` output generation
- Algorithm listing → `./dsa_toolbox list-algorithms`
- Version flag (`--version`)

#### 7. Visualizer-Based Enhancements (Advanced)
- `--viz` flag for step-by-step visual outputs (SVG, Graphviz, JSON logs)
- Example: `QuickSort` step tracing with `--trace`

#### 8. Web or GUI Interface Support (Most Advanced)
- **Web Frontend:** `dsa-toolbox-web` SPA (Vue/React)
- **WebAssembly Bridge:** `dsa-toolbox-core` C++ backend with WebAssembly (emscripten)

---

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

---

## Contact
Questions? Reach out:  
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Your_Profile-blue.svg)](https://www.linkedin.com/in/togunchan/)
