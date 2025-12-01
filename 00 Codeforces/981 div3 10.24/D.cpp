#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,s,a[100010];
void solve()
{
	cin>>n;
	map<int,int>mp;
	ans=0;
	s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
		if(!s||mp.count(s))
		{
			ans++;
			s=0;
			mp.clear();
		}
		mp[s]=1;
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
