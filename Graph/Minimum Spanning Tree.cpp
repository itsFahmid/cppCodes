#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };

const int MAX = 10; // small graph only
int parent[MAX], rnk[MAX];

void MakeSet(int v) { parent[v] = v; rnk[v] = 0; }

int FindSet(int v) { return parent[v] == v ? v : FindSet(parent[v]); }

void Union(int a, int b) {
    a = FindSet(a); b = FindSet(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
}

void UndoUnion(int a, int b, int oldParentB, int oldRankA) {
    parent[b] = oldParentB;
    rnk[a] = oldRankA;
}

// Recursive backtracking
void countMST(int n, vector<Edge>& edges, int idx, int edgesSelected, int totalWeight, int minWeight, long long &count) {
    if (edgesSelected == n-1) {
        if (totalWeight == minWeight) count++;
        return;
    }
    if (idx == edges.size()) return;

    int u = edges[idx].u, v = edges[idx].v;
    int rootU = FindSet(u), rootV = FindSet(v);

    // Option 1: Pick edge if it does not form a cycle
    if (rootU != rootV) {
        int oldParentV = parent[rootV];
        int oldRankU = rnk[rootU];
        Union(u, v);
        countMST(n, edges, idx+1, edgesSelected+1, totalWeight + edges[idx].w, minWeight, count);
        UndoUnion(rootU, rootV, oldParentV, oldRankU); // backtrack
    }

    // Option 2: Skip edge
    countMST(n, edges, idx+1, edgesSelected, totalWeight, minWeight, count);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--; edges[i].v--;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w < b.w; });

    // First, find minimum MST weight using standard Kruskal
    for (int i = 0; i < n; i++) MakeSet(i);
    int totalWeight = 0;
    for (auto &e : edges) {
        if (FindSet(e.u) != FindSet(e.v)) {
            Union(e.u, e.v);
            totalWeight += e.w;
        }
    }

    long long count = 0;
    for (int i = 0; i < n; i++) MakeSet(i); // reset DSU
    countMST(n, edges, 0, 0, 0, totalWeight, count);

    cout << "Minimum MST weight = " << totalWeight << "\n";
    cout << "Number of possible MSTs = " << count << "\n";
}
