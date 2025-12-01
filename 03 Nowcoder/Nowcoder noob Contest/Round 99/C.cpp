#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>mx,my;
int n,m,x,y,x1,y11,f;
int vt[1010][1010];
char a[1010][1010];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void dfs(int x,int y)
{
	vt[x][y]=1;
	mx[x]=1;
	my[y]=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m||vt[nx][ny]) continue;
		if(a[nx][ny]!='#') dfs(nx,ny);
	}
}

void dfs1(int x,int y)
{
	if(mx.count(x)||my.count(y)) f=1;
	vt[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m||vt[nx][ny]) continue;
		if(mx.count(nx)||my.count(ny)) f=1;
		if(a[nx][ny]!='#') dfs1(nx,ny);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++) 
	{
		cin>>a[i][j];
		if(a[i][j]=='S')
		{
			x=i;
			y=j;
		}
		else if(a[i][j]=='E')
		{
			x1=i;
			y11=j;
		}
	}
	f=0;
	dfs(x,y);
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++) vt[i][j]=0;
	dfs1(x1,y11);
	if(f) cout<<"YES\n";
	else cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
