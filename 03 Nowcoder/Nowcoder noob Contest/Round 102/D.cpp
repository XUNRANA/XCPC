#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,u,v,a[200010];
vector<int>g[200010];
int dis[200010][11];
int vt[200010][11];
//dis[v][i] ??? ????i?????v? 
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i],g[i].clear(); 
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
    
	for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) dis[i][j]=1e18,vt[i][j]=0;
	
    priority_queue< array<int,3>,vector<array<int,3>>,greater<array<int,3>> >q;
	
    q.push({0,1,1});
	
    dis[1][1]=1;
    
    q.push({a[1],1,0});
	
    dis[1][0]=a[1];
    
	while(!q.empty())
	{
		int u=q.top()[1];
		int j=q.top()[2];
		q.pop();
		if(vt[u][j]) continue;
		vt[u][j]=1;
		for(auto v:g[u])
		{
            if(dis[v][0]>dis[u][j]+a[v])
            {
                dis[v][0]=dis[u][j]+a[v];
                q.push({dis[v][0],v,0});
            }
            if(j<k)
			{
				if(dis[v][j+1]>dis[u][j]+1)
				{
					dis[v][j+1]=dis[u][j]+1;
					q.push({dis[v][j+1],v,j+1});
				}
			}
		}	
	}
	int ans=1e18;
	for(int i=0;i<=k;i++) ans=min(ans,dis[n][i]);
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
