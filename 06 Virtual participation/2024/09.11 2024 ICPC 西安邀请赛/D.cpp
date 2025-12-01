#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,res,ans,a[200010],b[200010];
void solve()
{
	ans=1e18;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i],res+=b[i];
	
	for(int k=0;k<=n;k++)
	{
		map<int,int>mp;
		for(int i=1;i<=n;i++) 
		{
			mp[a[i]-(i-1)*k]+=b[i];
			if((i-1)*k>1e6) break;
		}
		
		for(auto i:mp)
		{
			if(i.first>=0) ans=min(ans,res-i.second);
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
