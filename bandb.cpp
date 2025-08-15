#include <bits/stdc++.h>
using namespace std;

struct PathState {
    vector<int> path;
    int cost;
    bool operator>(const PathState &other) const {
        return cost > other.cost;
    }
};

int branchAndBound(int start, int goal, vector<vector<pair<int,int>>> &graph) {
    priority_queue<PathState, vector<PathState>, greater<PathState>> pq;
    pq.push({{start}, 0});

    int bestCost = INT_MAX;
    vector<int> bestPath;

    while (!pq.empty()) {
        PathState current = pq.top();
        pq.pop();

        int node = current.path.back();
        int cost = current.cost;

        if (cost >= bestCost) continue; 

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

    int n = 5;
    vector<vector<pair<int,int>>> graph(n);

    
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[2].push_back({4, 7});
    graph[4].push_back({3, 1});

    branchAndBound(0, 3, graph);

    return 0;
}
