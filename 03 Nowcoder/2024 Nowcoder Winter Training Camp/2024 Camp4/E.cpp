#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010],s,ans;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		s=(s+a[i])%k;
		if(s==0||mp.count(s))
		{
			ans++;
			s=0;
			mp.clear();
		}
		else mp[s]++;
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
