#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // For memcpy

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, w;
};

const int MAX = 1000;
int parent[MAX], rnk[MAX];
int n, m;
vector<Edge> edges;
vector<Edge> result_mst;
int mst_count = 0;
int min_total_weight = -1; // To store the weight of the first found MST

// DSU functions (unchanged)
void MakeSet(int v) {
    parent[v] = v;
    rnk[v] = 0;
}
int FindSet(int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = FindSet(parent[v]);
}
void Union(int a, int b) {
    a = FindSet(a);
    b = FindSet(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
}

// Helper function to print a found MST
void printMST() {
    int totalWeight = 0;
    for (const auto& e : result_mst) {
        totalWeight += e.w;
    }

    // This check ensures we only print trees with the minimum weight
    if (min_total_weight == -1) {
        min_total_weight = totalWeight;
    }
    if (totalWeight > min_total_weight) {
        return; // This is a non-minimum spanning tree, so we prune it.
    }

    mst_count++;
    cout << "MST #" << mst_count << ":\n";
    for (const auto& e : result_mst) {
        cout << e.u << " - " << e.v << " (" << e.w << ")\n";
    }
    cout << "Total weight = " << totalWeight << "\n\n";
}

// MODIFIED Recursive function to explore combinations
void generateCombinations(int cand_idx, const vector<Edge>& candidates, int next_block_idx, int required_edges, int edges_taken);

// Main recursive solver that processes edges block by block
void solve(int edge_idx) {
    // Base Case: If we have a spanning tree (n-1 edges), print it.
    if (result_mst.size() == n - 1) {
        printMST();
        return;
    }

    // Termination Case: If we run out of edges but don't have an MST.
    if (edge_idx >= m) {
        return;
    }

    // Find the block of all edges with the same weight
    int end_idx = edge_idx;
    while (end_idx < m && edges[end_idx].w == edges[edge_idx].w) {
        end_idx++;
    }

    // Identify candidate edges from this block that don't form a cycle with the current MST forest
    vector<Edge> candidates;
    for (int i = edge_idx; i < end_idx; ++i) {
        if (FindSet(edges[i].u) != FindSet(edges[i].v)) {
            candidates.push_back(edges[i]);
        }
    }

    // *** THE FIX ***
    // Calculate how many edges from this block we MUST take.
    // We do this by seeing how many candidates we can greedily add to a temporary DSU.
    int required_edges = 0;
    int temp_parent[MAX], temp_rnk[MAX];
    memcpy(temp_parent, parent, sizeof(parent));
    memcpy(temp_rnk, rnk, sizeof(rnk));
    for(const auto& cand : candidates) {
        if (FindSet(cand.u) != FindSet(cand.v)) {
            Union(cand.u, cand.v);
            required_edges++;
        }
    }
    // Restore original DSU state for the actual backtracking
    memcpy(parent, temp_parent, sizeof(parent));
    memcpy(rnk, temp_rnk, sizeof(rnk));

    // Backtracking part: explore all valid combinations
    generateCombinations(0, candidates, end_idx, required_edges, 0);
}


// MODIFIED function to explore combinations
void generateCombinations(int cand_idx, const vector<Edge>& candidates, int next_block_idx, int required_edges, int edges_taken) {
    // Base Case for this helper: we've considered all candidates in the current block.
    if (cand_idx == candidates.size()) {
        // Only proceed if we have taken the required number of edges
        if (edges_taken == required_edges) {
            solve(next_block_idx);
        }
        return;
    }

    // Save current DSU state for backtracking the "skip" path
    int temp_parent[MAX], temp_rnk[MAX];
    memcpy(temp_parent, parent, sizeof(parent));
    memcpy(temp_rnk, rnk, sizeof(rnk));

    // --- Path 1: Include candidates[cand_idx] ---
    Edge e = candidates[cand_idx];
    if (FindSet(e.u) != FindSet(e.v)) {
        result_mst.push_back(e);
        Union(e.u, e.v);
        // Recurse, noting we have taken one more edge
        generateCombinations(cand_idx + 1, candidates, next_block_idx, required_edges, edges_taken + 1);
        // Backtrack
        result_mst.pop_back();
        memcpy(parent, temp_parent, sizeof(parent)); // Restore DSU for the next path
        memcpy(rnk, temp_rnk, sizeof(rnk));
    }

    // --- Path 2: Don't include candidates[cand_idx] ---
    // We can only skip an edge if we still have enough future candidates to meet the required_edges count.
    int remaining_candidates = candidates.size() - (cand_idx + 1);
    int remaining_required = required_edges - edges_taken;
    if (remaining_candidates >= remaining_required) {
        generateCombinations(cand_idx + 1, candidates, next_block_idx, required_edges, edges_taken);
    }
}

int main() {
    cout << "Enter number of vertices and edges:\n";
    cin >> n >> m;
    edges.resize(m);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort all edges by weight
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    // Initialize DSU
    for (int i = 0; i < n; i++) {
        MakeSet(i);
    }

    cout << "\n--- All Possible Minimum Spanning Trees ---\n\n";

    // Start the recursive process from the first edge
    solve(0);

    if (mst_count == 0) {
        cout << "No MST found. The graph might be disconnected.\n";
    }

    return 0;
}
