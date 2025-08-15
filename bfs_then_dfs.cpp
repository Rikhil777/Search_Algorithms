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

    // Step 1: BFS to get level ordering
    vector<int> level(N, -1);
    queue<int> q;
    q.push(S);
    level[S] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    // Step 2: DFS but expand nodes in BFS level order
    vector<int> vis(N, 0), parent(N, -1);
    bool found = false;

    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        if (u == T) { found = true; return; }
        vector<int> neigh = g[u];
        sort(neigh.begin(), neigh.end(), [&](int a, int b) {
            int la = (level[a] == -1 ? 1e9 : level[a]);
            int lb = (level[b] == -1 ? 1e9 : level[b]);
            return la < lb;
        });
        for (int v : neigh) {
            if (!vis[v]) {
                parent[v] = u;
                dfs(v);
                if (found) return;
            }
        }
    };

    dfs(S);

    if (!vis[T]) {
        cout << "No path\n";
        return 0;
    }

    vector<int> path;
    for (int v = T; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    cout << "BFS-DFS combined path: ";
    for (int x : path) cout << x << " ";
    cout << "\n";
}
