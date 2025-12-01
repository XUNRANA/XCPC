#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans,a[7][7];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int cx(int x)
{
	return (x>=1&&x<=n);
}
int cy(int y)
{
	return (y>=1&&y<=m);
}
void dfs()
{
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++)
	{
		if(a[i][j])
		{
			int nx1,ny1,nx2,ny2;
			for(int k=0;k<4;k++)
			{
				nx1=i+dx[k];
				ny1=j+dy[k];
				nx2=i+2*dx[k];
				ny2=j+2*dy[k];
				if(cx(nx1)&&cx(nx2)&&cy(ny1)&&cy(ny2)&&a[nx1][ny1]&&a[nx2][ny2]==0)
				{
					a[i][j]=0;
					a[nx1][ny1]=0;
					a[nx2][ny2]=1;
					dfs();
					a[i][j]=1;
					a[nx1][ny1]=1;
					a[nx2][ny2]=0;
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]) cnt++;
	ans=min(cnt,ans);
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=0;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
	}
	ans=k;
	dfs();
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();  
}
