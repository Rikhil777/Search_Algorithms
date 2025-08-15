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
    queue<int> q;

    q.push(S);
    visited[S] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        history.push_back(u);

        if (u == T) break;

        for (int v : g[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

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
