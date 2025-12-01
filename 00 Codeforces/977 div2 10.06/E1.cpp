#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p,a[410],u,v,w;
int dis[410][410];
int vt[410];
void solve()
{
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
	for(int i=1;i<=n;i++) vt[i]=0,dis[i][i]=0;
	for(int i=1;i<=p;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dis[j][k]=min(dis[j][k],max(dis[j][i],dis[i][k]));
			}
		}
	}
	
	vector<int>d(p+1,1e18);
	for(int k=1;k<=n;k++)
	{
		int sum=1e18,idx=0;
		for(int i=1;i<=n;i++)
		{
			if(vt[i]) continue;
			int s=0;
			for(int j=1;j<=p;j++) s+=min(d[j],dis[i][a[j]]);
			if(s<sum)
			{
				sum=s;
				idx=i;
			}
		}
		cout<<sum<<" ";
		vt[idx]=1;
		for(int j=1;j<=p;j++) d[j]=min(d[j],dis[idx][a[j]]);
	} 
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
