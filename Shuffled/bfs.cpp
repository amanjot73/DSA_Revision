#include <bits/stdc++.h>
using namespace std;
int main() {
    int V, E;
    cin >> V >> E;
    // Adjacency list
    vector<vector<int>> adj(V);
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(V,false);
    vector<int>answer;
    queue<int>q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int top = q.front();
        // visited[top] = true;
        q.pop();
        answer.push_back(top);
        for(auto neigh : adj[top]){
            if(!visited[neigh]){
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    for(auto &i : answer){
        cout<<i<<" ";
    }
}