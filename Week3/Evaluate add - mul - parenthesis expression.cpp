#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int precedence(char op) {
    if (op == '+') return 1;
    if (op == '*') return 2;
    return 0; 
}
int Oper(int a, int b, char op) {
    if (op == '+') return (a + b) % MOD;
    if (op == '*') return (a * b) % MOD;
    return 0;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    stack<int> st_val;
    stack<char> st_op;
    int state = 0; 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' || s[i] == '\r') continue;
        if (s[i] == '(') {
            if (state == 1) { 
                cout << "NOT_CORRECT";
                return 0;
            }
            st_op.push(s[i]);
            state = 0;
        } 
        else if (s[i] == ')') {
            if (state == 0) { 
                cout << "NOT_CORRECT";
                return 0;
            }
            while (!st_op.empty() && st_op.top() != '(') {
                if (st_val.size() < 2) {
                    cout << "NOT_CORRECT";
                    return 0;
                }
                int val2 = st_val.top(); 
				st_val.pop();
                int val1 = st_val.top(); 
				st_val.pop();
                char op = st_op.top(); 
				st_op.pop();
                st_val.push(Oper(val1, val2, op));
            }
            if (st_op.empty()) { 
                cout << "NOT_CORRECT";
                return 0;
            }
            st_op.pop(); 
            state = 1;
        } 
        else if (isdigit(s[i])) {
            if (state == 1) { 
                cout << "NOT_CORRECT";
                return 0;
            }
            int val = 0;
            while (i < s.length() && isdigit(s[i])) {
                val = (val * 10 + (s[i] - '0')) % MOD;
                i++;
            }
            i--; 
            st_val.push(val);
            state = 1;
        } 
        else if (s[i] == '+' || s[i] == '*') {
            if (state == 0) { 
                cout << "NOT_CORRECT";
                return 0;
            }
            while (!st_op.empty() && precedence(st_op.top()) >= precedence(s[i])) {
                if (st_val.size() < 2) {
                    cout << "NOT_CORRECT";
                    return 0;
                }
                int val2 = st_val.top(); 
				st_val.pop();
                int val1 = st_val.top(); 
				st_val.pop();
                char op = st_op.top(); 
				st_op.pop();
                st_val.push(Oper(val1, val2, op));
            }
            st_op.push(s[i]);
            state = 0;
        } 
        else {
            cout << "NOT_CORRECT";
            return 0;
        }
    }
    if (state == 0) {
        cout << "NOT_CORRECT";
        return 0;
    }
    while (!st_op.empty()) {
        if (st_op.top() == '(' || st_op.top() == ')') {
            cout << "NOT_CORRECT";
            return 0;
        }
        if (st_val.size() < 2) {
            cout << "NOT_CORRECT";
            return 0;
        }
        int val2 = st_val.top(); 
		st_val.pop();
        int val1 = st_val.top(); 
		st_val.pop();
        char op = st_op.top(); 
		st_op.pop();
        st_val.push(Oper(val1, val2, op));
    }
    if (st_val.size() == 1) cout << st_val.top();
    else cout << "NOT_CORRECT";
}

