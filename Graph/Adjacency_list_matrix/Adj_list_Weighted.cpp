#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<pair<int, int>> adj[N];

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;

        // add value in a directed adj list;
        // adj[u].push_back({v, w});

        // add value in a undirected adj list;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    //print Adjacency list
    for(int i=1; i<=n; i++){
        cout<<"Node "<<i<<" Adjacency : ";
        for(auto j:adj[i]){
            cout<<"("<<j.first<<" "<<j.second<<") ";
        }
        cout<<endl;
    }
}