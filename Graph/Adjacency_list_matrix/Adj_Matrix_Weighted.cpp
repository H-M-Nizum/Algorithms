#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int adj[N][N];

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        // add value in a directed adj Matrix;
        // adj[u][v] = 1;

        // add value in a undirected adj Matrix;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // print adj matrix
    for(int i=1; i<=n; i++){
        cout<<"Node "<<i<<" Adj_Mat : ";
        for(int j=1; j<=n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}