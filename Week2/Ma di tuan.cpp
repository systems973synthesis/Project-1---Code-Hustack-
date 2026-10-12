#include<bits/stdc++.h>
#define int long long
using namespace std;
const int infi = 1e18;
int n, r, c, score = 0;
int a[11][11];
int maxx = -infi;
int dX[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dY[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool visited[11][11] = {false};
void Backtrack(int pointX, int pointY) {
	for (int i = 0; i < 8; i++) {
		int x = pointX + dX[i];
		int y = pointY + dY[i];
		if (x > n || y > n || x < 1 || y < 1 || visited[x][y] == true) continue;
		else {
			visited[x][y] = true;
			score += a[x][y];
			maxx = max(maxx, score);
			Backtrack(x, y);
			score -= a[x][y];
			visited[x][y] = false;
		}
	}
}
signed main() {
	cin >> n >> r >> c;
    for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++) {
            cin >> a[i][j];		
		}
	}	
	score += a[r][c]; 
    maxx = score; 
    visited[r][c] = true;
    Backtrack(r, c);
	cout << maxx;
}

