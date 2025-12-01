#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	int r,b,m;
	cin>>r>>b>>m;
	if((r+2*b+4*m)%4==0) cout<<"Bob\n";
	else cout<<"Alice\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

