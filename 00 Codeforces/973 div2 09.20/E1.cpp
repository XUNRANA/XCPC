#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100010],n,g,ans,g1;
void solve()
{
	cin>>n;
	ans=g1=g=0;
	for(int i=1;i<=n;i++) cin>>a[i],g1=__gcd(g1,a[i]);
	
	for(int i=0;i<n;i++)
	{
		int mi=1e9;
		for(int j=1;j<=n;j++) mi=min(mi,__gcd(g,a[j]));
		g=mi;
		ans+=g;
		if(g==g1) 
		{
			ans+=g1*(n-i-1);
			break;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
