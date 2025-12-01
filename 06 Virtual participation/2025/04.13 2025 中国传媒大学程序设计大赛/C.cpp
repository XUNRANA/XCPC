#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010][1010];
int n,m;
int dx[]={0,0,-1,1,-1,-1,1,1,0,0,-2,2};
int dy[]={-1,1,0,0,-1,1,-1,1,-2,2,0,0};
void fx1(int i,int j)
{
	a[i][j]=1;
	for(int k=0;k<4;k++)
	{
		int ni=dx[k]+i;
		int nj=dy[k]+j;
		if(ni<1||ni>n||nj<1||nj>m) continue;
		a[ni][nj]=1;
	}
}
void fx2(int i,int j)
{
	a[i][j]=1;
	for(int k=0;k<12;k++)
	{
		int ni=dx[k]+i;
		int nj=dy[k]+j;
		if(ni<1||ni>n||nj<1||nj>m) continue;
		a[ni][nj]=1;
	}
}
int d[1010][1010];
int vt[1010][1010];
void dij()
{
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) d[i][j]=1e9,vt[i][j]=0;
	priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
	d[1][1]=0;
	q.push({0,1,1});
	while(!q.empty())
	{
		int x=q.top()[1];
		int y=q.top()[2];
		q.pop();
		if(vt[x][y]) continue;
		vt[x][y]=1;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]) continue;
			if(d[nx][ny]>d[x][y]+1)
			{
				d[nx][ny]=d[x][y]+1;
				q.push({d[nx][ny],nx,ny});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='*') fx1(i,j);
			else if(ch=='#') fx2(i,j);
		}
	}
	
	// for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";

	dij();
	if(d[n][m]==1e9||a[1][1]||a[n][m]) d[n][m]=-1;
	cout<<d[n][m]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}  
