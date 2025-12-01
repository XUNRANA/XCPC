#include <bits/stdc++.h>
using namespace std;

int n,d[200010];
vector<int>g[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) d[i]=0,g[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		d[u]++;
		d[v]++;
	}

	multiset<int>st;
	for(int i=1;i<=n;i++) st.insert(d[i]);
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(auto v:g[i])
		{
			ans=max(ans,d[i]-1+d[v]-1);
			st.erase(st.find(d[v]));
		}
		st.erase(st.find(d[i]));
		
		if(st.size()) ans=max(ans,d[i]-1+(*st.rbegin()));
		
		for(auto v:g[i]) st.insert(d[v]);
		st.insert(d[i]);
	}
	
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
