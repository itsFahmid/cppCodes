#include<bits/stdc++.h>
using namespace std;

// code for doing dfs in all vertices
void DFSrec(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &res, int s){
    visited[s] = true;
    res.push_back(s);
    for(int it : adj[s]){
        if(visited[s] == false){
            DFSrec(adj, visited, res, it);
        }
    }
}

vector<int> DFSAll(vector<vector<int>> &adj, int V){
    vector<bool> visited(V, false);
    vector<int> res;
    for(int i=0; i<V; i++){
        DFSrec(adj, visited, res, i);
    }
    return res;
}

int main(){
    int V, E, u, v;
    cout << "Please input the amount of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj(V);

    for(int i=0; i<E; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> res = DFSAll(adj, V);
    for(int it : res){
        cout << it;
    }
}
