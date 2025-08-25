#include <bits/stdc++.h>
using namespace std;

int main() {
    bool flag = true;
    int n;
    long long k;
    cin >> n >> k;
    string s;
    cin >> s;

    unordered_map<string, long long> visited;
    vector<string> states;
    vector<bool> flags;

    for (long long i = 0; i < k; i++) {
        string key = s + (flag ? "1" : "0");
        if (visited.count(key)) {
            long long start = visited[key];
            long long cycle_length = i - start;
            long long remaining = (k - i) % cycle_length;
            s = states[start + remaining];
            cout << s << "\n";
            return 0;
        }

        visited[key] = i;
        states.push_back(s);
        flags.push_back(flag);

        if (flag) {
            flag = false;
            swap(s[0], s[n - 1]);
            for (int j = 0; j < n / 2; j++) {
                swap(s[j], s[n / 2 + j]);
            }
            cout << s << "\n";
        } else {
            flag = true;
            swap(s[n / 2], s[(n / 2) - 1]);
            reverse(s.begin(), s.end());
            cout << s << "\n";
        }
    }

    cout << s << "\n";
    return 0;
}
