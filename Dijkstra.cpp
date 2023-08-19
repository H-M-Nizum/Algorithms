// sssp -> singlr source shortest path
// fund shortest path in a weighted graph.

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9+7;

const int N = 1e3+5;
vector<pii> adj[N];
vector<bool> visited(N);

vector<int> dist(N, INF);

void difkstra(int s){
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min heap.
    dist[s] = 0;
    pq.push({dist[s], s});
    // weight based shortest path, so pq te weight first.

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(pii vpair: adj[u]){
            if(visited[vpair.first]) continue;
            // vpair.first = v, vpair.second = w
            if(dist[vpair.first] > dist[u] + vpair.second){
                dist[vpair.first] = dist[u] + vpair.second;
                pq.push({dist[vpair.first], vpair.first});

            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    difkstra(1);

    for(int i=1; i<=n; i++){
        cout<<"node "<<i<<" : "<<dist[i]<<endl;
    }
}