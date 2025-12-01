#include <bits/stdc++.h>
using namespace std;
vector<int>g[500010];
int a[500010];
int ans[500010];
void solve()
{
	int n,u,v;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],g[i].clear(),ans[i]=0;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for(int i=1;i<=n;i++)
	{
		set<int>st;
		for(auto j:g[i])
		{
			if(a[j]==a[i]) ans[a[i]]=1;
			if(st.count(a[j])) ans[a[j]]=1;
			else st.insert(a[j]);
		}
	}
	
	for(int i=1;i<=n;i++) cout<<ans[i];
	cout<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
