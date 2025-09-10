#include <bits/stdc++.h>
using namespace std;

// x[] is a global array to store the column position of the queen for each row.
// x[k] = i means the queen in row 'k' is placed in column 'i'.
// We'll use a vector for dynamic sizing. Index 0 will be unused to match
// the 1-based indexing of the pseudocode.
vector<int> x;
int solutionCount = 0;

/**
 * @brief Checks if a queen can be placed in row k and column i.
 * This function directly implements the 'Algorithm Place(k, i)' from the pseudocode.
 * @param k The current row (1-based index).
 * @param i The current column to check (1-based index).
 * @return True if the position is safe, false otherwise.
 */
bool Place(int k, int i) {      // for blocked cell, bring changes in here
    // 'for j := 1 to k - 1 do'
    // This loop checks against all previously placed queens in rows 1 to k-1.
    for (int j = 1; j < k; ++j) {
        // 'if (x[j] = i or Abs(x[j] - i) = Abs(j - k))'
        // Check for two conditions:
        // 1. x[j] == i: Is there another queen in the same column?
        // 2. abs(x[j] - i) == abs(j - k): Is there another queen on the same diagonal?
        //    The diagonal condition is true if the difference in columns equals the
        //    difference in rows.
        if ( (x[j] == i || abs(x[j] - i) == abs(j - k) )) {
            return false; // The position is under attack.
        }
    }
    return true; // The position is safe.
}

/**
 * @brief Prints a single solution by visualizing the board.
 * @param n The size of the board.
 */
void printSolution(int n) {
    solutionCount++;
    cout << "--- Solution " << solutionCount << " ---" << endl;
    // We iterate from row 1 to n.
    for (int k = 1; k <= n; ++k) {
        // For each row, we iterate through all columns.
        for (int i = 1; i <= n; ++i) {
            // If the column 'i' matches the stored position for queen 'k', print 'Q'.
            if (x[k] == i) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


/**
 * @brief Uses backtracking to find all placements of N queens on an N x N board.
 * This function directly implements the 'Algorithm NQueens(k, n)' from the pseudocode.
 * @param k The current row (1-based index) we are trying to place a queen in.
 * @param n The total number of queens (and the size of the board).
 */
void NQueens(int k, int n) {
    // 'for i := 1 to n do'
    // Try to place a queen in each column 'i' for the current row 'k'.
    for (int i = 1; i <= n; ++i) {
        // 'if Place(k, i) then'
        // Check if placing a queen at row 'k', column 'i' is safe.
        if (Place(k, i)) {
            // 'x[k] := i;'
            // If it's safe, place the queen.
            x[k] = i;

            // 'if (k = n) then write (x[1:n]);'
            // If we have successfully placed a queen in the last row,
            // we have found a complete, valid solution.
            if (k == n) {
                printSolution(n);
            } else {
                // 'else NQueens(k + 1, n);'
                // If not the last row, move to the next row and repeat the process.
                NQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number." << endl;
        return 1;
    }

    // Resize the vector to hold N+1 elements to use 1-based indexing.
    x.resize(n + 1);

    cout << "\nFinding all solutions for the " << n << "-Queens problem...\n" << endl;

    // Start the recursive search from the first row (k=1).
    NQueens(1, n);

    if (solutionCount == 0) {
        cout << "No solutions found for N = " << n << "." << endl;
    }

    return 0;
}

