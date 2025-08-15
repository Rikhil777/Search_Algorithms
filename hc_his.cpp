#include <bits/stdc++.h>
using namespace std;

int hillClimbWithHistory(int start, int goal,
                         vector<vector<pair<int,int>>> &graph,
                         vector<int> &heuristic) {
    int current = start;
    vector<int> path = {current};
    vector<bool> visited(graph.size(), false);
    visited[current] = true;

    while (current != goal) {
        int bestNeighbor = -1;
        int bestHeuristic = heuristic[current];

        for (auto &edge : graph[current]) {
            int next = edge.first;
            if (!visited[next] && heuristic[next] < bestHeuristic) {
                bestHeuristic = heuristic[next];
                bestNeighbor = next;
            }
        }

        if (bestNeighbor == -1) { // No unvisited better neighbor
            cout << "No better unvisited neighbor found. Stopping.\n";
            break;
        }

        current = bestNeighbor;
        visited[current] = true;
        path.push_back(current);
    }

    cout << "Path taken: ";
    for (int node : path) cout << node << " ";
    cout << "\n";

    if (current == goal) {
        cout << "Goal reached successfully!\n";
    } else {
        cout << "Goal not reached.\n";
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 6; // number of nodes
    vector<vector<pair<int,int>>> graph(n);

    // Weighted graph (weights unused in hill climbing)
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[1].push_back({4, 10});
    graph[2].push_back({4, 7});
    graph[4].push_back({3, 1});
    graph[3].push_back({5, 3});
    graph[4].push_back({5, 2});

    // Heuristic values (lower = better)
    vector<int> heuristic = {7, 6, 5, 3, 2, 0};

    hillClimbWithHistory(0, 5, graph, heuristic);

    return 0;
}
