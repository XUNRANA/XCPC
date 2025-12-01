#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[20],u,v,ans;
vector<pair<int,int>>c;
void dfs(int i)
{
	if(i==m)
	{
		int cnt=0;
		for(int i=2;i<=n;i++)
		if(a[i]>a[1]) cnt++;
		ans=min(ans,cnt+1);
////		cout<<cnt+1<<"\n";
////		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
////		cout<<"\n";
		return ;
	}

	a[c[i].first]+=3;
	dfs(i+1);
	a[c[i].first]-=3;
	
	a[c[i].second]+=3;
	dfs(i+1);
	a[c[i].second]-=3;
	
	a[c[i].first]++;
	a[c[i].second]++;
	dfs(i+1);
	a[c[i].first]--;
	a[c[i].second]--;
	return ;
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	c.clear();
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		c.push_back({u,v});
	}
	ans=n;
	dfs(0);
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
