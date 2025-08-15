#include <bits/stdc++.h>
using namespace std;
int N = 8;
vector<vector<int>> g = {{1,2},{3,4},{5},{6},{6},{4,7},{7},{}};
int START=0, GOAL=7;
vector<int> path;
bool dfs_limit(int u, int depth, vector<int>& visited){
    if(depth<0) return false;
    if(u==GOAL){ path.push_back(u); return true; }
    visited[u]=1;
    for(int v: g[u]){
        if(!visited[v]){
            if(dfs_limit(v, depth-1, visited)) { path.push_back(u); return true; }
        }
    }
    visited[u]=0;
    return false;
}
int main(){
    for(int limit=0; limit<=N-1; ++limit){
        vector<int> visited(N,0);
        path.clear();
        if(dfs_limit(START, limit, visited)) break;
    }
    reverse(path.begin(), path.end());
    if(path.empty()) cout<<"No path";
    else{ 
        cout<<"Path: "; for(int x: path) cout<<x<<" "; cout<<" "; 
    }
}