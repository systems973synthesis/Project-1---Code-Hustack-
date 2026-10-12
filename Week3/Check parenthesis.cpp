#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    string s;
    cin >> s;
    stack<char> st;
    bool check = true; 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        else {
            if (st.empty()) {
                check = false;
                break;
            }
            if (s[i] == '}') {
                if (st.top() == '{') st.pop();
                else { 
                	check = false;
                	break;
                }
            }
            else if (s[i] == ')') {
                if (st.top() == '(') st.pop();
                else {
                	check = false;
                	break;
                }
            }
            else if (s[i] == ']') {
                if (st.top() == '[') st.pop();
                else { 
                	check = false;
                	break;
                }
            }
        }
    }
    if (!st.empty()) check = false; 
    if (check == true) cout << 1;
    else cout << 0;
}

