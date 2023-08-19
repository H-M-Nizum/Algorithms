#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int adj[N][N];

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;

        // add value in a directed adj Matrix;
        adj[u][v] = w;

        // add value in a directed adj Matrix;
        // adj[u][v] = w;
        // adj[v][u] = w;
    }

    //print Adjacency Matrix
    for(int i=1; i<=n; i++){
        cout<<"Node "<<i<<" Adj_Mat : ";
        for(int j=1; j<=n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}