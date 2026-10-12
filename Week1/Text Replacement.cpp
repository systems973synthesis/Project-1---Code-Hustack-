#include<bits/stdc++.h>
#define int long long
using namespace std;
const int base=317;
const int MOD=1e9+7;
const int SZ=1000111;
int PW[SZ],HshS[SZ],cnt=0;
int HashS(int i, int j) {
	return (HshS[j]-HshS[i-1]*PW[j-i+1]+MOD*MOD)%MOD;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string SS, SH, SP;
	vector<int> pos;
	getline(cin, SH);
	getline(cin, SP);
	getline(cin, SS);
	int Ssze=SS.size(), Hsze=SH.size(), Psze=SP.size();
	SS=" "+SS;
	SH=" "+SH;
	PW[0]=1;
	for (int i=1; i<=Ssze; i++) {
		PW[i]=(PW[i-1]*base)%MOD;
	}
	for (int i=1; i<=Ssze; i++) {
		HshS[i]=(HshS[i-1]*base+SS[i]-'A'+1)%MOD;
	}
	int HshH=0;
	for (int i=1; i<=Hsze; i++) {
		HshH=(HshH*base+SH[i]-'A'+1)%MOD;
	}
	int t=0;
	for (int i=1; i<=Ssze-Hsze+1; i++) {
		if (HshH==HashS(i, i+Hsze-1)) {
			SS.replace(i+(Psze-Hsze)*t, Hsze, SP);
			t++;
		}
	}
	for (int i=1; i<=SS.size(); i++) {
		cout<<SS[i];
	}
}

