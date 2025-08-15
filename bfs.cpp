#include <bits/stdc++.h>
using namespace std;
int N3=8;
vector<vector<int>> g3={{1,2},{3,4},{5},{6},{6},{4,7},{7},{}};
int S3=0, T3=7;
int main(){
    vector<int> parent(N3,-1), vis(N3,0);
    queue<int>q; q.push(S3); vis[S3]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        if(u==T3) break;
        for(int v: g3[u]) if(!vis[v]){ vis[v]=1; parent[v]=u; q.push(v); }
    }
    if(parent[T3]==-1 && S3!=T3){ cout<<"No path"; return 0; }
    vector<int> path;
    for(int v=T3; v!=-1; v=parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    cout<<"BFS path: "; for(int x:path) cout<<x<<" "; cout<<" ";
    
}
