#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,x,y,nx,ny;
int dis[1010][1010],vt[1010][1010];
char a[1010][1010];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j],dis[i][j]=1e9;
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{1,1}});
    dis[1][1]=0;
    while(!q.empty())
    {
        x=q.front().second.first;
        y=q.front().second.second;
        q.pop();
        if(vt[x][y]) continue;
        vt[x][y]=1;
        for(int i=0;i<4;i++)
        {
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(vt[nx][ny]||a[nx][ny]==a[x][y]) continue;
            dis[nx][ny]=dis[x][y]+1;
            q.push({dis[nx][ny],{nx,ny}});
        }
    }
    if(dis[n][m]==1e9) dis[n][m]=-1;
    cout<<dis[n][m];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

