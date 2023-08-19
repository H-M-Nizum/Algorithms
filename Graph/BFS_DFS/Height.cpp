#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];
int height[N];

void calculate_height(int u){
    visited[u] = true;

    for(int v:adj[u]){
        if(visited[v]) continue;
        calculate_height(v);
        height[u] = max(height[u], height[v]+1);
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

    calculate_height(1);
    // print height

    for(int i=1; i<=n; i++){
        cout<<"Node "<<i<<" Height: "<<height[i]<<endl;
    }
}