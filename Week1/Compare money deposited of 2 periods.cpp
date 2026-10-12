#include <bits/stdc++.h>
#define int long long
using namespace std;
const int SZ = 1e6 + 5;
int n, m, a[SZ], pre[SZ];
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    cin >> m;
    while (m--) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        if (pre[j1] - pre[i1 - 1] < pre[j2] - pre[i2 - 1]) cout << "1\n";
        else cout << "0\n";
    }
}

