#include <bits/stdc++.h>
using namespace std;
int N2=8;
vector<vector<int>> g2={{1,2},{3,4},{5},{6},{6},{4,7},{7},{}};
int S2=0, T2=7;
vector<int> parent2;
vector<int> visited2;
bool found2=false;
void dfs2(int u){
    visited2[u]=1;
    if(u==T2){ 
        found2=true; 
        return; 
    }
    for(int v: g2[u]) 
        if(!visited2[v]){ 
            parent2[v]=u; 
            dfs2(v); 
            if(found2) return; 
        }
}
int main(){
    parent2.assign(N2,-1);
    visited2.assign(N2,0);
    dfs2(S2);
    if(!visited2[T2]){ cout<<"No path"; return 0; }
    vector<int> path2;
    for(int v=T2; v!=-1; v=parent2[v]) path2.push_back(v);
    reverse(path2.begin(), path2.end());
    cout<<"Visited set: ";
    for(int i=0;i<N2;i++) if(visited2[i]) cout<<i<<" ";
    cout<<"Path: "; for(int x: path2) cout<<x<<" "; cout<<" ";
}