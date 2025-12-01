#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
void solve()
{
	cin>>n>>m;
	vector<pair<int,int>>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i].second;
	for(int i=1;i<=n;i++) cin>>a[i].first;
	sort(a.begin()+1,a.end());
	vector<int>v;
	int i=1;
	while(i<=n) 
	{
		int cnt=1;
		int mx=a[i].first+a[i].second;
		while(i+1<=n&&mx>=a[i+1].first)
		{
			i++;
			mx=max(mx,a[i].first+a[i].second);
			cnt++;
		}
		v.push_back(cnt);
		i++;
	}
	sort(v.begin(),v.end(),greater<int>());
	ans=0;
	for(int i=0;i<min(m,(int)v.size());i++) ans+=v[i];
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
