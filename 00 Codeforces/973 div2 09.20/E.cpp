#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100010],n,ans,g,c;
void solve()
{
	cin>>n;
	ans=g=c=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g=__gcd(g,a[i]);
	}
	for(int i=1;i<=n;i++) a[i]/=g;
	
	for(int t=0;t<n;t++)
	{
		int nc=1e9;
		for(int i=1;i<=n;i++) nc=min(nc,__gcd(c,a[i]));
		c=nc;
		ans+=c;
		if(c==1)
		{
			ans+=n-t-1;
			break;
		}
	}
	cout<<ans*g<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
