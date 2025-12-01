#include <bits/stdc++.h>
using namespace std;

set<int>g[100010];
int n,m,p,x;
int c[100010],ans[100010];
void solve()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) c[i]=0,g[i].clear(),ans[i]=i;
	
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		while(p--)
		{
			cin>>x;
			g[i].insert(x);
			c[x]=i;
		}
	}
	
	for(int i=2;i<=n;i++)
	{
		vector<int>vt;
		for(auto j:g[i-1])
		{
			if(g[i].count(j))
			{
				vt.push_back(j);
			}
		}
		
		int f=0;
		for(auto j:vt)
		if(c[j]==i)
		{
			f=1;
			break;
		}
		
		if(!f)
		{
			cout<<"Yes\n";
			swap(ans[i-1],ans[i]);
			for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
			cout<<"\n";
			return ;
		}
	}
	cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
