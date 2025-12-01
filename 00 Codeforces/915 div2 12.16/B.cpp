#include <bits/stdc++.h>
using namespace std;
int n,u,v,cnt;
vector<int>g[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cnt=0;
	for(int i=1;i<=n;i++) if(g[i].size()==1) cnt++;
	cout<<(cnt+1)/2<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t; 
	while(t--) solve();
}
