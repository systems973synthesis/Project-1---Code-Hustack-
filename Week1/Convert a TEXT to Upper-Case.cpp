#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    while (getline(cin, s)) {
    for (int i=0; i<s.size(); i++) {
        if (int(s[i])>=97 && int(s[i])<=122) {
            s[i]=s[i]-32;
        }
    }
    cout<<s<<"\n";
    }
}

