#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int SZ = 1e6 + 5;
int n, minn = 1e18, maxx = -1e18, sum = 0;
int a[SZ], lg[SZ], st[SZ][25];
string type, id;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }
    cin >> id; 
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; j <= lg[n]; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (cin >> type && type != "***") {
        if (type == "min" || type == "find-min") cout << minn << "\n";
        else if (type == "max" || type == "find-max") cout << maxx << "\n";
        else if (type == "sum") cout << sum << "\n";
        else if (type == "find-max-segment") {
            int l, r;
            cin >> l >> r;
            l--, r--; 
            int k = lg[r - l + 1];
            cout << max(st[l][k], st[r - (1 << k) + 1][k]) << "\n";
        }
    }
}

