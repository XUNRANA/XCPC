#include <bits/stdc++.h>
using namespace std;
#define N 1010
int n,a[N][N],dis[N][N],vt[N][N];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	for(int k=1;k<=n;k++) a[k][0]=a[k][n+1]=a[0][k]=a[n+1][k]=1;
	queue<pair<int,int>>q;
	q.push({1,1});
	vt[1][1]=1;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(a[nx][ny]==1)
			{
				while(a[nx-dx[i]][ny-dy[i]]==0) ny-=dy[i],nx-=dx[i];
			}
			if(vt[nx][ny]) continue;
			dis[nx][ny]=dis[x][y]+1;
			q.push({nx,ny});
			vt[nx][ny]=1;
		}
	}
	if(dis[n][n]==0) dis[n][n]=-1;
	cout<<dis[n][n];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

