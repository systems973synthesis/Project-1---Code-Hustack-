#include <bits/stdc++.h>
#define int long long
using namespace std;
const int SZ = 1e6 + 5;
int n, a[SZ], sum = 0;
signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum;
}

