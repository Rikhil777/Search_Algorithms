#include <bits/stdc++.h>
using namespace std;

struct NodeState {
    int node;
    int gCost; // cost so far
    int fCost; // gCost + heuristic
    vector<int> path;
    bool operator>(const NodeState &other) const {
        return fCost > other.fCost;
    }
};

int aStarSearch(int start, int goal,
                vector<vector<pair<int,int>>> &graph,
                vector<int> &heuristic) {
    priority_queue<NodeState, vector<NodeState>, greater<NodeState>> pq;
    pq.push({start, 0, heuristic[start], {start}});

    vector<int> bestCostToNode(graph.size(), INT_MAX);
    bestCostToNode[start] = 0;

    while (!pq.empty()) {
        NodeState current = pq.top();
        pq.pop();

        int node = current.node;
        int g = current.gCost;

        if (node == goal) {
            cout << "Best path found: ";
            for (int v : current.path) cout << v << " ";
            cout << "\nTotal cost: " << g << "\n";
            return g;
        }

        if (g > bestCostToNode[node]) continue;

        for (auto &edge : graph[node]) {
            int next = edge.first;
            int weight = edge.second;
            int newG = g + weight;

            if (newG < bestCostToNode[next]) {
                bestCostToNode[next] = newG;
                vector<int> newPath = current.path;
                newPath.push_back(next);
                int f = newG + heuristic[next];
                pq.push({next, newG, f, newPath});
            }
        }
    }

    cout << "No path found.\n";
    return -1;
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

    aStarSearch(0, 5, graph, heuristic);

    return 0;
}
