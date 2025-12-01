#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[310];
int d[310][310];
int s[310];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) d[i][j]=1e18;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		d[u][v]=d[v][u]=min(d[v][u],w);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	
	int res=1e18;
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++) 
	{
		int ans=0;
		for(int k=1;k<=n;k++) ans+=min(d[i][k],d[j][k])*a[k];
		res=min(res,ans);
	}
	cout<<res<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

