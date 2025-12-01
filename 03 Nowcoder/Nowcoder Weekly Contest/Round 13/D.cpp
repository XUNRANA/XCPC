#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define P 1000000007
#define int long long
int n,m,ans,ans1,dis[N],p[N];
vector<int>g[N];
void solve()
{
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=n;i++) 
	{
		dis[i]=1e9;
		p[i]=p[i-1]*2%P;
	}
	for(int i=1;i<=m;i++) 
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<pair<int,int> >q;
	q.push({0,1});
	dis[1]=0;
	while(!q.empty())
	{
		int d=q.front().first;
		int u=q.front().second;
		q.pop();
        if(d>dis[u]) continue;
		for(auto v:g[u])
		{
			if(dis[u]+1<dis[v])
			{
				dis[v]=dis[u]+1;
				q.push({dis[v],v});
			}
		}
	}
    ans1=0;
	for(int i=1;i<=n;i++) ans1=(ans1+dis[i])%P;
	ans=1;
    int c1=0;
	for(int u=2;u<=n;u++)
	{
		int cnt=0;
		for(auto v:g[u])
		{
			if(dis[v]==dis[u]-1) cnt++;
            if(dis[v]==dis[u]) c1++;
		}
		if(cnt) ans=ans*(p[cnt]-1)%P;
	}
	cout<<ans1<<" "<<ans*p[c1/2]%P<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
