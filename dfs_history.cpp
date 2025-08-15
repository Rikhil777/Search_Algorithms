#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 8;
    vector<vector<int>> g = {
        {1, 2},   // 0
        {3, 4},   // 1
        {5},      // 2
        {6},      // 3
        {6},      // 4
        {4, 7},   // 5
        {7},      // 6
        {}        // 7
    };
    int S = 0, T = 7;

    vector<int> parent(N, -1), visited(N, 0), history;
    bool found = false;

    function<void(int)> dfs = [&](int u) {
        visited[u] = 1;
        history.push_back(u);
        if (u == T) { found = true; return; }
        for (int v : g[u]) {
            if (!visited[v]) {
                parent[v] = u;
                dfs(v);
                if (found) return;
            }
        }
    };

    dfs(S);

    if (!visited[T]) {
        cout << "No path\n";
        return 0;
    }

    vector<int> path;
    for (int v = T; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    cout << "History: ";
    for (int x : history) cout << x << " ";
    cout << "\nPath: ";
    for (int x : path) cout << x << " ";
    cout << "\n";
}
    