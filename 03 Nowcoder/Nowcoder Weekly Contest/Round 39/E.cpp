#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p,x,ans;
void solve()
{
	cin>>n>>m>>p>>x;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m&&i*j<x;j++)
		{
			int t=x-i*j;
			if(t%(2*i+2*j)==0&&t/(2*j+2*i)<=p) ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
