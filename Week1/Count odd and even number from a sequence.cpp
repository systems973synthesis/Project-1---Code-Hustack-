#include <bits/stdc++.h>
using namespace std;
const int SZ = 1e6 + 5;
int n, a[SZ], cnt = 0;
signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) cnt++;
    }
    cout << cnt << " " << n - cnt;
}

