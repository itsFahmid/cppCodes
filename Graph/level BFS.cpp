#include<bits/stdc++.h>
using namespace std;

void levelBFS(vector<vector<int>> &adj, int V, int s){
    vector<int> visited(V, false);
    vector<pair<int, int>> res;
    int level = 1;

    queue<pair<int, int>> q;

    q.push({s, level});
    visited[s] = true;

    while(!q.empty()){
        int curr = q.front().first;
        int level = q.front().second;
        q.pop();
        res.push_back({curr, level});
        for(auto i : adj[curr]){
            if(visited[i] == false){
                q.push({i, level + 1});
                visited[i] = true;
            }
        }
    }

    for(auto i : res){
        cout << i.first << " " << i.second << endl;
    }
}

int main(){
    int V, E, u, v;
    cout << "input vertices and edges";
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for(int i=0; i<E; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Input source";
    int s;
    cin >> s;
    levelBFS(adj, V, s);
}
/*
0 1
0 2
1 2
1 3
2 4
3 4
*/
