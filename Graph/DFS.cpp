#include<bits/stdc++.h>
using namespace std;

void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res){
    visited[s] = true;
    res.push_back(s);
    for(auto i : adj[s]){
        if(visited[i] == false){
            DFSRec(adj, visited, i, res);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj, int V, s){
    vector<int> res;
    vector<bool> visited(V, false);
    DFSRec(adj, visited, s, res);
    return res;
}

int main(){
    int V, E, u, v;
    cout << "Please input number of edges and vertices";
    cin >> E >> V;
    vector<vector<int>> adj(V);
    for(int i=0; i<E; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Please input source";
    int s;
    cin >> s;
    vector<int> res = dfs(adj, V, s);
    for(auto it : res){
        cout << it;
    }
}
