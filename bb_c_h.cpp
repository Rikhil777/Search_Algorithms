#include <bits/stdc++.h>
using namespace std;

struct PathState {
    vector<int> path;
    int gCost; // actual cost so far
    int fCost; // gCost + heuristic
    bool operator>(const PathState &other) const {
        return fCost > other.fCost;
    }
};

int branchBoundHeuristic(int start, int goal,
                         vector<vector<pair<int,int>>> &graph,
                         vector<int> &heuristic) {
    priority_queue<PathState, vector<PathState>, greater<PathState>> pq;
    pq.push({{start}, 0, heuristic[start]});

    int bestCost = INT_MAX;
    vector<int> bestPath;

    while (!pq.empty()) {
        PathState current = pq.top();
        pq.pop();

        int node = current.path.back();
        int g = current.gCost;

        if (current.fCost >= bestCost) continue; // prune

        if (node == goal) {
            bestCost = g;
            bestPath = current.path;
            continue;
        }

        for (auto &edge : graph[node]) {
            int next = edge.first;
            int weight = edge.second;
            if (find(current.path.begin(), current.path.end(), next) == current.path.end()) {
                vector<int> newPath = current.path;
                newPath.push_back(next);
                int newG = g + weight;
                int newF = newG + heuristic[next];
                pq.push({newPath, newG, newF});
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

    // Graph edges with weights
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[1].push_back({4, 10});
    graph[2].push_back({4, 7});
    graph[4].push_back({3, 1});
    graph[3].push_back({5, 3});
    graph[4].push_back({5, 2});

    // Heuristic values (estimated cost from node to goal = node 5)
    vector<int> heuristic = {7, 6, 5, 3, 2, 0};

    branchBoundHeuristic(0, 5, graph, heuristic);

    return 0;
}
