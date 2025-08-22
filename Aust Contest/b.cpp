#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, message;
        int key;

        cin >> s >> key;
        cin.ignore();
        getline(cin, message);
        int x = key;

        int n = message.length();

        for (int i = 0; i < n; i++) {
            if (message[i] >= 'a' && message[i] <= 'z') {
                message[i] = ( (26 - (key % 26) ) + (message[i] - 'a') ) % 26 + 'a';
            }
            else if (message[i] >= 'A' && message[i] <= 'Z') {
                message[i] = ( (26 - (key % 26) ) + (message[i] - 'A') ) % 26 + 'A';
            }
        }

        cout << s << " " << x << ":" << message << endl;
    }
}

