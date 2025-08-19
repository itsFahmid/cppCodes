#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<vector<int>> &adj, int s, int V){
    vector<int> res;
    vector<int> visited(V, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for(int x : adj[curr]){
            if(visited[x] == false){
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return res;
}

int main(){
    int V, E, u, v;
    cout << "Please enter number of edges & vertices:" << endl;
    cin >> n;
    vector<vector<int>> adj(V);
    for(int i=0; i<E; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Enter source";
    int s;
    cin >> s;

    vector<int> res = BFS(adj, s, V);

    for(auto it : res){
        cout << res;
    }
}
