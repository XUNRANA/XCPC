#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int x,y,z,a,b,t;
	cin>>x>>y>>z>>a>>b>>t;
	int l=0,s=0,ans=0;
	for(int i=1;i<=t;i++)
	{
		if(i%x==0) s+=a;
		if(i%y==0)
		{
			if(i-l<z) continue;
			else 
			{
				l=i;
				ans+=min(s,b);
				s-=min(s,b);
			}
		}
	} 
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
