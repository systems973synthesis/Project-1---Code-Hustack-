#include <bits/stdc++.h>
#define int long long
using namespace std;
const int SZ = 1e5 + 5;
int n, k, a[SZ], sum[SZ];
signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    int cnt = 0;
    for (int i = 0; i <= n - k; i++) {
        if ((sum[i + k] - sum[i]) % 2 == 0) cnt++;
    }
    cout << cnt;
}

