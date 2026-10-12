#include<bits/stdc++.h>
#define int long long
using namespace std;
const int infi = 1e18 + 1;
int m, n, q;
int ans = infi, missing = 0; 
bool can[11][31]; 
int crd[31], lb[11];
int load[11] = {0}, num[11] = {0};
int visited[31] = {0};
vector<int> adj[31];
bool check(int i, int j) {
    if (!can[i][j]) return false; 
    for (int x : adj[j]) {
        if (visited[x] == i) return false;
    }
    return true;
} 
void Solve() {
    int maxx = 0;
    for (int i = 1; i <= m; i++) {
        maxx = max(maxx, load[i]);
    }
    ans = min(ans, maxx);
}
void Backtrack(int j) {
    for (int i = 1; i <= m; i++) {
        if (load[i] + crd[j] < ans && check(i, j)) {
            visited[j] = i;
            load[i] += crd[j];
            if (num[i] < lb[i]) missing--; 
            num[i]++;
            if (missing <= n - j) {
                if (j == n) Solve();
                else Backtrack(j + 1);
            }
            num[i]--;
            if (num[i] < lb[i]) missing++; 
            load[i] -= crd[j];
            visited[j] = 0;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int a, x;
        cin >> a;
        for (int j = 1; j <= a; j++) {
            cin >> x;
            can[i][x] = true; 
        }
    }   
    for (int i = 1; i <= n; i++) cin >> crd[i];
    for (int i = 1; i <= m; i++) {
        cin >> lb[i];
        missing += lb[i]; 
    }
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    Backtrack(1);
    if (ans == infi) cout << -1;
    else cout << ans;
}

