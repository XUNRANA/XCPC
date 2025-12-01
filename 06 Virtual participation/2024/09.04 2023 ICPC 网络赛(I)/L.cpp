#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,T,t;
	cin>>n>>T;
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		mx=max(mx,t);
	}
	cout<<max(2ll,(mx+T-1)/T)<<"\n";
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
