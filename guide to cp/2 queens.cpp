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
