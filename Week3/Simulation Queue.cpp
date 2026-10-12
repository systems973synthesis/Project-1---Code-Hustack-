#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    string s;
    int v;
    queue<int> q;
    do {
        cin >> s;
        if (s == "PUSH") {
            cin >> v;
            q.push(v);
        }
        else if (s == "POP") {
            if (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << "\n";
            }
            else cout << "NULL\n";
        }
    } while (s != "#");
}

