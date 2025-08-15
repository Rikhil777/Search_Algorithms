# Search Algorithms Collection

This repository contains implementations of various AI search algorithms in C++.  
Each algorithm solves the same graph-based pathfinding problem but uses different strategies.

---

## Algorithms

### 1. [British Museum Search](bms.cpp)
A brute-force method that tries **every possible path** until it finds the goal.  
It is not practical for large problems but guarantees finding a solution if one exists.

### 2. [Depth First Search (DFS)](dfs.cpp)
Explores as far as possible along one branch before backtracking.  
Uses a stack (or recursion) to remember where to return.

### 3. [Breadth First Search (BFS)](bfs.cpp)
Explores all nodes at the current depth before moving deeper.  
Uses a queue to process nodes level by level. Guarantees shortest path in an unweighted graph.

### 4. [BFS + DFS Combination](bfs_then_dfs.cpp)
Runs BFS first, and if the goal is not found, switches to DFS for deeper exploration.

### 5. [DFS with History](dfs_history.cpp)
A DFS variation that keeps a record of visited nodes to prevent revisiting them and avoid cycles.

### 6. [BFS with History](bfs_history.cpp)
A BFS variation that also stores visited nodes to prevent repeated processing of the same node.

### 7. [Hill Climb](hc.cpp)
An optimization search that moves to the **neighbor with the best heuristic value**.  
Stops when no better neighbor is found.

### 8. [Hill Climb with History](hc_his.cpp)
Hill Climb that remembers visited states to avoid revisiting and getting stuck in small loops.

### 9. [Beam Search](beam_search.cpp)
Keeps only a fixed number (**beam width**) of the best candidates at each step, based on heuristic values.  
Faster but may miss the optimal path.

### 10. [Beam Search with History](bs_history.cpp)
Beam Search that also avoids revisiting previously explored nodes.

### 11. [Oracle Search](oracle.cpp)
Uses a “perfect” heuristic that **magically knows** the exact best move towards the goal, simulating an oracle.

### 12. [Branch and Bound](bandb.cpp)
Expands the most promising node based on the **path cost so far**, pruning worse paths early.

### 13. [Branch and Bound with Cost + Estimated Heuristics](bb_c_h.cpp)
Adds an **estimated heuristic** to the path cost (like A* but still branch and bound style) to guide the search.

### 14. [Branch and Bound with History](bb_his.cpp)
Branch and Bound that keeps track of visited nodes to avoid revisiting them.

### 15. [A* Search](aSTAR.cpp)
Uses `f(n) = g(n) + h(n)` where:
- `g(n)` is the path cost so far
- `h(n)` is the heuristic estimate to the goal  
Guarantees optimal path if heuristic is admissible.

---

## How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/Rikhil777/Search_Algorithms.git

2. Compile the desired algorithm.
    ```bash
    g++ AlgorithmName.cpp -o algorithm
3. Run it
    ```bash
    ./algorithm
