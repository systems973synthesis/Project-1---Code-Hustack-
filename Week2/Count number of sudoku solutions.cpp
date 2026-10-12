#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10][10], cnt = 0;
bool isValid(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (a[row][i] == num || a[i][col] == num) {
            return false; 
        }
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[startRow + i][startCol + j] == num) {
                return false; 
            }
        }
    }
    return true;
}
bool findEmptyCell(int &row, int &col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (a[row][col] == 0) return true; 
        }
    }
    return false;
}
void Solutions() {
    int row, col;
    if (!findEmptyCell(row, col)) {
        cnt++;
        return; 
    }
    for (int num = 1; num <= 9; num++) {
        if (isValid(row, col, num)) {
            a[row][col] = num; 
            Solutions(); 
            a[row][col] = 0; 
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
        }
    }
    Solutions();
    cout << cnt;
}

