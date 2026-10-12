#include<bits/stdc++.h>
#define int long long
using namespace std;
const int SZ=1001;
string s;
signed main() {
	getline(cin, s);
	if (s.size()!=8) cout<<"INCORRECT";
	else if (s[2]!=':' || s[5]!=':') cout<<"INCORRECT";
	else if ((s[0]=='2' && s[1]>='5') || (s[0]>='3')) cout<<"INCORRECT";
	else if (s[3]>='6' || s[6]>='6') cout<<"INCORRECT";
	else {
		cout<<((s[0]-'0')*10+(s[1]-'0'))*3600+((s[3]-'0')*10+(s[4]-'0'))*60+((s[6]-'0')*10+(s[7]-'0'));
	}
}

