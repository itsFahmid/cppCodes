#include<bits/stdc++.h>
using namespace std;

vector<int> BFSall(vector<vector<int>> &adj, int V){
    vector<bool> visited(V, false);
    vector<int> res;

    queue<int> q;

    for(int i=0; i<V; i++){
        if(visited[i] == false){
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                res.push_back(curr);
                for(int it : adj[curr]){
                    if(visited[it] == false){
                        visited[it] = true;
                        q.push(it);
                    }
                }
            }
        }
    }
    return res;
}

int main(){
    int V, E, u, v;
    cout << "Please enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj(V);

    for(int i=0; i<E; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> res = BFSall(adj, V);

    for(int it : res){
        cout << it << " ";
    }
    cout << endl;
}
