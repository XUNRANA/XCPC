#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[510][510];
int vt[510][510];
int d[510][510];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void solve()
{
    int n,m,q,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) 
        {
            a[i][j]=0;
            vt[i][j]=0;
            d[i][j]=1e9;
        }
        cin>>q;
        while(q--)
        {
            cin>>x;
            a[i][x]=1;
        }
    }
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
    for(int i=1;i<=n;i++) 
    if(!a[i][1]) 
    {
        d[i][1]=1;
        pq.push({d[i][1],i,1});
    }
    while(!pq.empty())
    {
        int x=pq.top()[1];
        int y=pq.top()[2];
        pq.pop();
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
                pq.push({d[nx][ny],nx,ny});
            }
        }
    }
    
    int ans=1e9;
    for(int i=1;i<=n;i++) ans=min(ans,d[i][m]);
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
