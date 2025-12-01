#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,u,v,a[5010],ans;
vector<pair<int,int>>g[5010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back({a[v],v});
		g[v].push_back({a[u],u});
	}
	for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end(),greater<pair<int,int>>());



	for(int i=1;i<=n;i++)
	{
		int res=a[i];
		ans=max(ans,res);
		for(int j=0;j<g[i].size();j++)
		{
			res+=g[i][j].first;
			ans=max(ans,res);
			for(int k=j+1;k<g[i].size();k++)
			{
				res+=g[i][k].first;
				
				
				ans=max(ans,res);
				
				set<pair<int,int>>st;
				st.insert({a[i],i});
				st.insert(g[i][j]);
				st.insert(g[i][k]);
				vector<pair<int,int>>c,b;
				
				for(auto t:g[g[i][j].second])
				{
					if(!st.count(t)) ans=max(ans,res+t.first);
					c.push_back(t);
					if(c.size()==4) break;
				}
				for(auto t:g[g[i][k].second])
				{
					if(!st.count(t)) ans=max(ans,res+t.first);
					b.push_back(t);
					if(b.size()==4) break;
				}
				
				for(int i1=0;i1<c.size();i1++)
				{
					for(int j1=0;j1<b.size();j1++)
					{
						if(!st.count(c[i1])&&!st.count(b[j1])&&c[i1]!=b[j1])
						{
							ans=max(ans,res+c[i1].first+b[j1].first);
						}
					}
				}	
				
						
				res-=g[i][k].first;
			}
			res-=g[i][j].first;
		}
	}
	cout<<ans<<"\n";
}
 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
