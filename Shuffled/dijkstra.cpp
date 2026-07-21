#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    // Adjacency list
    vector<vector<pair<int,int>>> adj(V);

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Undirected graph
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout<<"Enter Src\n";
    int src;
    cin >> src;
    vector<int>distance(V,INT_MAX);
    set<pair<int,int>> pq;
    distance[src] = 0;
    pq.insert(make_pair(0,src));
    while(!pq.empty()){
        auto it = pq.begin();
        int top = it->second;
        int dis  = it->first;
        pq.erase(it);
        for(auto &neigh: adj[top]){
            int nxtnode = neigh.first;
            int dis2 = neigh.second;
            int n = dis2+dis;
            if(n<distance[nxtnode]){
                if(distance[nxtnode]!=INT_MAX){
                    pq.erase(make_pair(dis2,nxtnode));
                }
                distance[nxtnode] = n;
                pq.insert(make_pair(n,nxtnode));
            }
        }
    }
    for(int i = 0;i<distance.size();i++){
        cout<<i<<" -> "<< distance[i]<<endl;
    }

}
// 5 6
// 0 1 10
// 0 2 5
// 1 2 2
// 1 3 1
// 2 3 9
// 2 4 2
// 0
