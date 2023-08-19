#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];
int depth[N];


void calculate_depth(int u){
    visited[u] = true;

    for(int v: adj[u]){
        if(visited[v]) continue;
        depth[v] = depth[u]+1;
        calculate_depth(v);
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    calculate_depth(1);
    
    // print depth
    for(int i=1; i<=n; i++){
        cout<<"Node "<<i<<" Depth: "<<depth[i]<<endl;;
    }
}