#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,a[510][510];
void solve()
{
	cin>>n;
	ans=0;
	map<int,int>mp;
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++)	
		{
			cin>>a[i][j];
			if(mp.count(i-j)) mp[i-j]=min(mp[i-j],a[i][j]);
			else mp[i-j]=a[i][j];
		}
	}
	for(auto i:mp) if(i.second<0) ans+=-i.second;
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
