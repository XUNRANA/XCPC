#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,y,dis[110][110],vt[110][110],c[110];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
char a[110][110];
vector<pair<int,pair<int,int>>>g[110][110];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j],dis[i][j]=1e9;
    for(int i=1;i<=m;i++) dis[n+1][i]=1e9;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1) g[i][j].push_back({c[1],{n+1,1}});
            if(j+1<=m) g[i][j].push_back({c[j+1],{n+1,j+1}});
            for(int k=0;k<4;k++)
            {
                x=i+dx[k];
                y=j+dy[k];
                if(x<1||x>n||y<1||y>m) continue;
                if(a[x][y]=='.') g[i][j].push_back({0,{x,y}});
            }
        }
    }
    for(int j=1;j<=m;j++) for(int i=1;i<=n;i++) g[n+1][j].push_back({0,{i,j}});
    
   // g[1][1].push_back({c[1],{n+1,1}});
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >q;
    q.push({0,{1,1}});
    dis[1][1]=0;
    while(!q.empty())
    {
        int w=q.top().first;
        x=q.top().second.first;
        y=q.top().second.second;
        q.pop();
        if(vt[x][y]) continue;
        vt[x][y]=1;
        for(auto v:g[x][y])
        {
            int nw=v.first;
            int nx=v.second.first;
            int ny=v.second.second;
            if(dis[nx][ny]>dis[x][y]+nw)
            {
                dis[nx][ny]=dis[x][y]+nw;
                q.push({dis[nx][ny],{nx,ny}});
            }
        }
    }
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
