#include<bits/stdc++.h>
#define int long long
using namespace std;
const int SZ=1e6+5;
int n,m,a[SZ];
signed main() {
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    int x=1, y=n, cnt=0;
    while (x<y) {
        if (a[x]+a[y]==m) {
            cnt++;
            x++;
            y--;
        }
        else if (a[x]+a[y]<m) x++;
        else if (a[x]+a[y]>m) y--;
    }
    cout<<cnt;
}

