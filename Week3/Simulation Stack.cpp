#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    string s;
    int v;
    stack<int> st;
    do {
        cin >> s;
        if (s == "PUSH") {
            cin >> v;
            st.push(v);
        }
        else if (s == "POP") {
            if (!st.empty()) {
            int u = st.top();
            st.pop();
            cout << u << "\n";
            }
            else cout << "NULL\n";
        }
    } while (s != "#");
}

