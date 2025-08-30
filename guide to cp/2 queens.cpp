#include <bits/stdc++.h>
using namespace std;

long long possiblePositions(long long n)
{
    long long term1 = pow(n, 4);
    long long term2 = pow(n, 3);
    long long term3 = pow(n, 2);
    long long term4 = n / 3;
    return (ceil)(term1) / 2 - (ceil)(5 * term2) / 3 + (ceil)(3 * term3) / 2 - term4; // The formula is: (n^4 / 2) - (5n^3 / 3) + (3n^2 / 2) - (n / 3)
}

int main()
{
    long long n;
    n = 3;

    long long ans = possiblePositions(n);
    cout << ans << endl;
    return 0;
}

/*
If we do not place the queen on the last row and the last column then the answer will simply be the number of positions to place in a chessboard of (N-1) * (N-1)
whereas if we place in the last column and last row then possible positions for queens will be 2N−1
and attacking at 3(N−1)
positions. Therefore, the possible positions for the other queen for each position of the queen will be −3(N−1)−1.
Finally, there are (N−1)(N−2)
combinations where both queens are on the last row and last column. Therefore, the recurrence relation will be:
Q(N)=Q(N−1)+(2N−1)[N^2−3(N−1)−1]−(N−1)(N−2)// By Induction

Collected from Geek-for-Geek
*/
