#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    double oldCost = 0, newCost = 0;

    // Bieu gia hien hanh - 6 bac
    if (n > 0) oldCost += min(n, 50) * 1728.0;
    if (n > 50) oldCost += min(n - 50, 50) * 1786.0;
    if (n > 100) oldCost += min(n - 100, 100) * 2074.0;
    if (n > 200) oldCost += min(n - 200, 100) * 2612.0;
    if (n > 300) oldCost += min(n - 300, 100) * 2919.0;
    if (n > 400) oldCost += (n - 400) * 3015.0;

    // Bieu gia de xuat - 5 bac
    if (n > 0) newCost += min(n, 100) * 1728.0;
    if (n > 100) newCost += min(n - 100, 100) * 2074.0;
    if (n > 200) newCost += min(n - 200, 200) * 2612.0;
    if (n > 400) newCost += min(n - 400, 300) * 3111.0;
    if (n > 700) newCost += (n - 700) * 3457.0;

    // Tinh chenh lech sau VAT 10%
    double diff = (newCost - oldCost) * 1.1;

    cout << fixed << setprecision(2) << diff;

    return 0;
}

