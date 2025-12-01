#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int dis[60][60],n,m,x,y;
bool G[60][60][65];
//G[i][j][k]表示i到j是否有长度为(1<<k)的路径 
void solve()
{
	memset(dis,inf,sizeof dis);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		dis[x][y]=1;
		G[x][y][0]=1;
	}
	for(int k=1;k<=64;k++)
	for(int i=1;i<=n;i++)//起点 
	for(int t=1;t<=n;t++)//中间点 
	for(int j=1;j<=n;j++)//终点 
	if(G[i][t][k-1]&&G[t][j][k-1])
	{
		G[i][j][k]=1;//i到j存在一个路径,长度为(1<<k) 
		dis[i][j]=1;//1s可从i到j 
	}
	for(int k=1;k<=n;k++)//中间点最前面 (floyd) 
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	cout<<dis[1][n]<<"\n"; 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
