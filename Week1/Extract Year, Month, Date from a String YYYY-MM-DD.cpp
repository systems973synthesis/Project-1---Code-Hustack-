#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    if (!s.empty() && s.back() == '\r') {
        s.pop_back();
    }
    if (s.length() != 10) {
        cout << "INCORRECT\n";
        return 0;
    }
    if (s[4] != '-' || s[7] != '-') {
        cout << "INCORRECT\n";
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue; 
        if (s[i] < '0' || s[i] > '9') {
            cout << "INCORRECT\n";
            return 0;
        }
    }
    int year = stoi(s.substr(0, 4));
    int month = stoi(s.substr(5, 2));
    int day = stoi(s.substr(8, 2));
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        cout << "INCORRECT\n";
        return 0;
    }
    cout << year << " " << month << " " << day << "\n";
    return 0;
}

