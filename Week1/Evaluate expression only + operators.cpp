#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int sohang=0,sum=0,i=0;
    string s;
    cin>>s;
    while (i<s.size()) {
        if (s[i]>='0' && s[i]<='9') {
            sohang=sohang*10+s[i]-'0';
            if (s[i+1]=='+' || i==s.size()-1) {
                sum+=sohang;
            }
        }
        else if (s[i]=='+') {
            sohang=0;
        }
        i++;
    }
    cout<<sum;
}

