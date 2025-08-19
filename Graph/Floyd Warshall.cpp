#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
void printvector(vector<vector<int>>& D) {
    int n = D.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == INF ) cout << "INF ";
            else cout << D[i][j] << " ";
        }
        cout << endl;
    }
}
void printpi(vector<vector<int>>& pi) {
    int n = pi.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pi[i][j] == -1) cout << "NIL ";
            else cout << pi[i][j]+1 << " ";
        }
        cout << endl;
    }
}
void floydWarshall(vector<vector<int>>& W,vector<vector<int>>& pi) {
    int n = W.size();
    vector<vector<int>> D(n, vector<int>(n));

    D = W;

    for (int k = 0; k < n; k++) {
        vector<vector<int>> newD = D;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] != INF && D[k][j] != INF && D[i][j] > D[i][k] + D[k][j] ) {
                        D[i][j] > D[i][k] + D[k][j];
                        newD[i][j] = D[i][k] + D[k][j];
                        pi[i][j] = pi[k][j];

                }
            }
        }
        D = newD;
    }

    cout << "All-pairs shortest path matrix:\n";
    printvector(D);
    cout << "Predecessor matrix:\n";
    printpi(pi);
}


int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> W(n, vector<int>(n, INF));
    vector<vector<int>> pi(n,vector<int>(n, -1));

    for (int i = 0; i < n; i++) W[i][i] = 0;

    cout << "Enter edges in format: u v w\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        W[u][v] = w;
        pi[u][v] = u;
    }

    floydWarshall(W,pi);

    return 0;
}
