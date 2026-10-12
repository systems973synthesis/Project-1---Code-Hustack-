#include <bits/stdc++.h>
using namespace std;
int n, x[21];
void Print(int n) {
    for (int i = 1; i <= n - 1; i++) {
        if (x[i] == x[i + 1] && x[i] == 1) return;
    }
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << "\n";
}
void Backtrack(int k) {
    for (int i = 0; i <= 1; i++) {
        x[k] = i;
        if (k == n) Print(n);
        else Backtrack(k + 1);
    }
}
int main() {
    cin >> n;
    Backtrack(1);
}

