#include <bits/stdc++.h>
using namespace std;
vector<int>g[200010];
int n,c,t,fa[200010];
int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) g[i].clear(),fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		while(c--)
		{
			cin>>t;
			g[i].push_back(t);
		}
	}
	
	vector<pair<int,int>>res;
	for(int i=n;i>=1;i--)
	{
		if(g[i].empty()) continue;
		
		for(auto v:g[i])
		{
			res.push_back({find(v),i});
			merge(v,i);
		}
	}
	
	for(auto i:res) cout<<i.first<<" "<<i.second<<"\n";
/*
2
4
2 3 4
1 3
0
0
3
1 3
1 3
0
*/
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
