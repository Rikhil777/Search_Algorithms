#include <bits/stdc++.h>
using namespace std;

// Oracle function: checks if the given path is the best one
bool oracleCheck(const vector<int> &path) {
    // For demo, assume the best path is {0, 1, 3}
    vector<int> best = {0, 1, 3};
    return path == best;
}

// DFS-based exploration until oracle confirms the best path
bool oracleDFS(int node, int target, vector<vector<int>> &graph,
               vector<bool> &visited, vector<int> &path) {
    path.push_back(node);
    if (oracleCheck(path)) return true; // Oracle says "This is the best"

    visited[node] = true;
    for (int neigh : graph[node]) {
        if (!visited[neigh]) {
            if (oracleDFS(neigh, target, graph, visited, path))
                return true; // Stop when found
        }
    }
    visited[node] = false;
    path.pop_back();
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5; // number of nodes
    vector<vector<int>> graph(n);

    // Add edges (undirected example)
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2};

    vector<bool> visited(n, false);
    vector<int> path;

    bool found = oracleDFS(0, 3, graph, visited, path);

    if (found) {
        cout << "Best path found by oracle: ";
        for (int node : path) cout << node << " ";
        cout << "\n";
    } else {
        cout << "No path found by oracle.\n";
    }

    return 0;
}
