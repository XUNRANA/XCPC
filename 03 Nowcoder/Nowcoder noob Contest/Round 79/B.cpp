#include <bits/stdc++.h>
using namespace std;
#define int long long
int s,mi=1e9,n,t;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		s+=t;
		if(t&1) mi=min(mi,t);
	}
	if(s&1) cout<<s-mi<<"\n";
	else cout<<s<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
