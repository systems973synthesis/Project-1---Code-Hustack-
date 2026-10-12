#include<bits/stdc++.h>
#define int long long
using namespace std;
const int SZ = 1005;
const int MOD = 1e9 + 7;
int n, k, dp[SZ][SZ];
signed main() {
    cin >> k >> n;
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
        }
    }
    cout << dp[n][k];
} 

