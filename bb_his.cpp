#include <bits/stdc++.h>
using namespace std;

struct PathState {
    vector<int> path;
    int cost;
    bool operator>(const PathState &other) const {
        return cost > other.cost;
    }
};

int branchAndBoundWithHistory(int start, int goal, vector<vector<pair<int,int>>> &graph) {
    priority_queue<PathState, vector<PathState>, greater<PathState>> pq;
    pq.push({{start}, 0});

    int n = graph.size();
    vector<int> bestCostToNode(n, INT_MAX); // history of best costs to each node
    bestCostToNode[start] = 0;

    int bestCost = INT_MAX;
    vector<int> bestPath;

    while (!pq.empty()) {
        PathState current = pq.top();
        pq.pop();

        int node = current.path.back();
        int cost = current.cost;

        // Prune paths worse than the best path found
        if (cost >= bestCost) continue;

        // History-based pruning: skip if we already reached this node cheaper
        if (cost > bestCostToNode[node]) continue;
        bestCostToNode[node] = cost;

        if (node == goal) {
            bestCost = cost;
            bestPath = current.path;
            continue;
        }

        for (auto &edge : graph[node]) {
            int next = edge.first;
            int weight = edge.second;
            if (find(current.path.begin(), current.path.end(), next) == current.path.end()) {
                vector<int> newPath = current.path;
                newPath.push_back(next);
                pq.push({newPath, cost + weight});
            }
        }
    }

    if (bestCost == INT_MAX) {
        cout << "No path found.\n";
        return -1;
    }

    cout << "Best path found: ";
    for (int v : bestPath) cout << v << " ";
    cout << "\nTotal cost: " << bestCost << "\n";

    return bestCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 6; // number of nodes
    vector<vector<pair<int,int>>> graph(n);

    // Graph edges: u -> v (weight)
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[1].push_back({4, 10});
    graph[2].push_back({4, 7});
    graph[4].push_back({3, 1});
    graph[3].push_back({5, 3});
    graph[4].push_back({5, 2});

    branchAndBoundWithHistory(0, 5, graph);

    return 0;
}
