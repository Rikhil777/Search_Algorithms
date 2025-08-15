#include <bits/stdc++.h>
using namespace std;

struct NodeState {
    int node;
    vector<int> path;
    int heuristicValue;
    bool operator<(const NodeState &other) const {
        return heuristicValue > other.heuristicValue; // smaller heuristic is better
    }
};

void beamSearch(int start, int goal,
                vector<vector<pair<int,int>>> &graph,
                vector<int> &heuristic, int beamWidth) {
    vector<NodeState> frontier;
    frontier.push_back({start, {start}, heuristic[start]});

    while (!frontier.empty()) {
        // Check if any candidate reached the goal
        for (auto &state : frontier) {
            if (state.node == goal) {
                cout << "Goal found! Path: ";
                for (int v : state.path) cout << v << " ";
                cout << "\n";
                return;
            }
        }

        vector<NodeState> nextFrontier;

        // Expand all nodes in current frontier
        for (auto &state : frontier) {
            for (auto &edge : graph[state.node]) {
                int next = edge.first;
                if (find(state.path.begin(), state.path.end(), next) == state.path.end()) {
                    vector<int> newPath = state.path;
                    newPath.push_back(next);
                    nextFrontier.push_back({next, newPath, heuristic[next]});
                }
            }
        }

        // Sort by heuristic value (best first)
        sort(nextFrontier.begin(), nextFrontier.end());

        // Keep only top-k candidates (beam width)
        if ((int)nextFrontier.size() > beamWidth)
            nextFrontier.resize(beamWidth);

        frontier = move(nextFrontier);
    }

    cout << "Goal not found.\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 6; // number of nodes
    vector<vector<pair<int,int>>> graph(n);

    // Weighted graph (weights unused in basic beam search)
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[1].push_back({4, 10});
    graph[2].push_back({4, 7});
    graph[4].push_back({3, 1});
    graph[3].push_back({5, 3});
    graph[4].push_back({5, 2});

    // Heuristic values (lower is better)
    vector<int> heuristic = {7, 6, 5, 3, 2, 0};

    int beamWidth = 2; // Keep only the best 2 nodes at each level
    beamSearch(0, 5, graph, heuristic, beamWidth);

    return 0;
}
