#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, visited[21] = {false}, x[21];
void Print() {
	for (int i = 1; i <= n; i++) {
		cout << x[i] << " ";
	}
	cout << "\n";
}
void Generate(int k) {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
		    visited[i] = true;
			x[k] = i;
		    if (k == n) Print();
		    else Generate(k + 1);
	    	visited[i] = false;
		}
	}
}
signed main() {
	cin >> n;
	Generate(1);
}

