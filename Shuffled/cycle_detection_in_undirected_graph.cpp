#include<bits/stdc++.h>
using namespace std;
int main() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<int>> edges;
    
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    vector<vector<int>> adj(V);
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(V,false);
    vector<int>parent(V,0);
    queue<int>q;
    q.push(0);
    visited[0] = true;
    parent[0] = -1;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto neigh : adj[top]){
            if(visited[neigh]== true && neigh != parent[top]){
                cout<<"Cycle is present";
                return 0;
            }
            else if(!visited[neigh]){
                q.push(neigh);
                visited[neigh] = true;
                parent[neigh] = top;
            }
        }
    }
    cout<<"Cycle not present";


}
