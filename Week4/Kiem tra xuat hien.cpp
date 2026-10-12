#include<bits/stdc++.h>
#define int long long
using namespace std;
const int SZ = 1e6 + 5;
int n, a[SZ];
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    set<int> s;
    for (int i = 1; i <= n; i++) {
    	if (s.find(a[i]) == s.end()) {
    		s.insert(a[i]);
    		cout << 0 << "\n";
    	}
    	else cout << 1 << "\n";
    }
}
