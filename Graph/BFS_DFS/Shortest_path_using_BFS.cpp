#include<bits/stdc++.h>
using namespace std;

const int N =1e5+5;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];



void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v:adj[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            
            level[v] = level[u]+1;
            parent[v] = u;
        }
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

    int s, d;
    cin>>s>>d;
    bfs(s);

    // source to dastination, shortest path distance
    cout<<"Distance : "<<level[d]<<endl;

    // path finding
    // dastination to source, back every nodes parent.
    vector<int> ans;
    int curr = d;

    while(curr != -1){
        ans.push_back(curr);
        curr = parent[curr];
    }

    // print sources to dastination
    reverse(ans.begin(), ans.end());
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

}