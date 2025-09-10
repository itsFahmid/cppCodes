#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Solves the 0-1 knapsack problem using dynamic programming.
 * * @param W The maximum capacity of the knapsack.
 * @param wt A vector containing the weights of the items.
 * @param val A vector containing the values (benefits) of the items.
 * @param n The number of items.
 */
void knapsack(int W, const std::vector<int>& wt, const std::vector<int>& val, int n) {
    // V[i][w] will store the maximum value that can be obtained using
    // a subset of the first 'i' items with a total weight limit of 'w'.
    // We use (n+1) x (W+1) size to easily handle 1-based indexing from the pseudocode.
    std::vector<std::vector<int>> V(n + 1, std::vector<int>(W + 1, 0));

    // ## Part 1: Build the DP Table ##
    // This section corresponds to the first pseudocode image.
    // It fills the table V in a bottom-up manner.
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            // Note: wt[i-1] and val[i-1] correspond to w_i and b_i from the
            // pseudocode, as C++ vectors are 0-indexed.

            // If the weight of the current item (i) is greater than the current
            // capacity (w), we cannot include it. The value is the same as the
            // solution for the previous item.
            if (wt[i - 1] > w) {
                V[i][w] = V[i - 1][w];
            } else {
                // We have a choice:
                // 1. Don't include item 'i': The value is V[i-1][w].
                // 2. Include item 'i': The value is its own value plus the value
                //    of the remaining capacity, i.e., val[i-1] + V[i-1][w - wt[i-1]].
                // We take the maximum of these two options.
                V[i][w] = std::max(V[i - 1][w], val[i - 1] + V[i - 1][w - wt[i - 1]]);
            }
        }
    }

    // The final answer for the maximum value is in the bottom-right corner.
    int maxValue = V[n][W];
    std::cout << "Maximum value in Knapsack = " << maxValue << std::endl;

    // ## Part 2: Find the Selected Items ##
    // This section corresponds to the second pseudocode image.
    // It backtracks from V[n][W] to find which items were included.
    std::cout << "Items selected:" << std::endl;
    std::vector<int> selectedItems;
    int k = W; // Start with the full capacity.

    for (int i = n; i > 0 && k > 0; --i) {
        // If the value in the current cell V[i][k] is different from the value
        // in the cell above it V[i-1][k], it means that item 'i' was included
        // in the optimal solution for this state.
        if (V[i][k] != V[i - 1][k]) {
            // Mark the item as part of the solution.
            selectedItems.push_back(i);

            // Decrease the remaining capacity by the weight of the included item.
            k -= wt[i - 1];
        }
        // If the values are the same, item 'i' was not included, so we just
        // move up to the previous item without changing the capacity 'k'.
    }

    // Print the items. They were added in reverse order, so we iterate backwards.
    for (int i = selectedItems.size() - 1; i >= 0; --i) {
        int itemIndex = selectedItems[i] - 1; // Convert back to 0-based index
        std::cout << "  Item " << selectedItems[i]
                  << " (Weight: " << wt[itemIndex]
                  << ", Value: " << val[itemIndex] << ")" << std::endl;
    }
}

int main() {
    // Example items
    std::vector<int> values = {60, 100, 120};
    std::vector<int> weights = {10, 20, 30};
    int capacity = 50;
    int numItems = values.size();

    knapsack(capacity, weights, values, numItems);

    return 0;
}
