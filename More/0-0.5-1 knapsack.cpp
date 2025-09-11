#include <bits/stdc++.h>
using namespace std;

// A structure to represent an item with its weight, profit, and index.
struct Item {
    int profit, weight, index;
};

/**
 * @brief Comparison function to sort items in descending order of their profit/weight ratio.
 * @param a The first item.
 * @param b The second item.
 * @return True if item 'a' has a higher or equal ratio than item 'b'.
 */
bool compareItems(Item a, Item b) {
    double ratio1 = (double)a.profit / a.weight;
    double ratio2 = (double)b.profit / b.weight;
    return ratio1 > ratio2;
}

/**
 * @brief Solves the Fractional Knapsack problem using a greedy algorithm.
 * @param m The maximum capacity of the knapsack.
 * @param items A vector of Item objects.
 * @param n The number of items.
 */
void greedyKnapsack(int m, vector<Item>& items, int n) {
    // 1. Sort items based on profit/weight ratio in descending order.
    // The pseudocode assumes the items are already sorted. In a real implementation,
    // we must perform this sorting step first.
    sort(items.begin(), items.end(), compareItems);

    // x[i] stores the fraction of item i taken.
    // This corresponds to x[1:n] in the pseudocode.
    vector<double> x(n, 0.0);

    // U is the remaining capacity of the knapsack.
    // Corresponds to U=m in the pseudocode.
    int U = m;
    double totalProfit = 0.0;

    // 2. Iterate through the sorted items and fill the knapsack.
    // This corresponds to the main loop in the pseudocode.
    for (int i = 0; i < n; ++i) {
        // If we can't fit any more items, break.
        // Corresponds to 'if (w[i] > U) then break;'.
        if ( (items[i].weight > U ) ) {
            // Take a fraction of the current item to fill the remaining capacity.
            // Corresponds to 'if (i <= n) then x[i] = U/w[i];'.
            if(items[i].weight / 2 < U){
                x[items[i].index] = 0.5;
                totalProfit += U * ((double)items[i].profit / (items[i].weight / 2) );
                U -= items[i].weight / 2; // Knapsack is now full
                break;
            }
            else{
                break;
            }

        }

        // If the item fits completely, take all of it.
        // Corresponds to 'x[i]=1; U=U-w[i];'.
        x[items[i].index] = 1.0; // Take the whole item
        U -= items[i].weight;
        totalProfit += items[i].profit;
    }

    // --- Output the results ---
    cout << "Maximum possible profit = " << fixed << setprecision(2) << totalProfit << endl;
    cout << "Fractions of items taken (by original index):" << endl;
    for (int i = 0; i < n; ++i) {
        if (x[i] > 0) {
            cout << "  Item " << i + 1 << ": " << fixed << setprecision(2) << x[i] * 100 << "%" << endl;
        }
    }
    cout << "Empty Space: " << U << endl;
}

int main() {
    // Knapsack capacity
    int capacity = 50;

    // Item details (profit, weight)
    vector<pair<int, int>> item_details = {{60, 10}, {100, 20}, {120, 30}};

    int n = item_details.size();
    vector<Item> items(n);
    for(int i = 0; i < n; ++i) {
        items[i].profit = item_details[i].first;
        items[i].weight = item_details[i].second;
        items[i].index = i;
    }

    greedyKnapsack(capacity, items, n);

    return 0;
}

