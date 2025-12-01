#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans;
int vt[11][11];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
char a[11][11];
void dfs(int x,int y,int s)
{
	if(s==k)
	{
		ans++;
		return ;
	}
	
	vt[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='#'||vt[nx][ny]) continue;
		dfs(nx,ny,s+1);
	}
	vt[x][y]=0;
	
}

void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	
	ans=0;
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++)
	{
		if(a[i][j]=='.')
		{
			dfs(i,j,0);
		}
	}
	cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
