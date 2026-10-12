#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, sum = 0;
vector<int> res;
void Print() {
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
}
void Backtrack(int i) {
    for (int j = i; sum + j <= n; j++) {
        sum += j;
        res.push_back(j);
        if (sum == n) Print();
        else Backtrack(j);
        res.pop_back();
        sum -= j;
    }
}
signed main() {
	cin >> n;
	Backtrack(1);
}

