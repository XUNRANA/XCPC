#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,a[200010],ans;
void solve()
{
	cin>>n;
	map<int,int>cnt;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		cnt[t]++;
	}
	for(auto i:cnt)
	{
		if(i.second==1)
		{
			cout<<"-1\n";
			return ;
		}
		ans+=(i.second+1)/2;
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
