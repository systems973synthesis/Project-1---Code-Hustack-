#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main() {
    double a,b,c,x,x1,x2;
    cin>>a>>b>>c;
    if (b*b-4*a*c<0) cout<<"NO SOLUTION";
    else if (b*b-4*a*c==0) {
        x=-b/(2*a);
        cout<<setprecision(2)<<fixed<<x;
    }
    else if (b*b-4*a*c>0) {
        double del=b*b-4*a*c;
        x1=(-b+sqrt(del))/(2*a);
        x2=(-b-sqrt(del))/(2*a);
        if (x1>x2) {
            cout<<setprecision(2)<<fixed<<x2<<" "<<setprecision(2)<<fixed<<x1;
        }
        else {
            cout<<setprecision(2)<<fixed<<x1<<" "<<setprecision(2)<<fixed<<x2;
        }
    }
}

