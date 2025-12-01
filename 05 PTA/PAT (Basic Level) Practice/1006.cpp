#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n;
    cin>>n;
    int b=n/100;
    n%=100;
    int s=n/10;
    n%=10;
    int g=n;
    while(b--) cout<<"B";
    while(s--) cout<<"S";
    for(int i=1;i<=g;i++) cout<<i;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}