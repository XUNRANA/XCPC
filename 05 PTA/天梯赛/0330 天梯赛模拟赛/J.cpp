#include <bits/stdc++.h>
using namespace std;
#define int long long
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,-1,1};
int a[1010][1010];
int vt[1010][1010];
int d[1010][1010];
int n,m,sx,sy,k,x,y,nx,ny;
void solve() 
{
    cin>>n>>m>>sx>>sy;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) d[i][j]=1e9;
    cin>>k;
    while(k--)
    {
        cin>>x>>y;
        for(int i=0;i<8;i++)
        {
            a[x][y]+=2;
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m) continue;
            a[nx][ny]++;
        }
    }
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    q.push({0,1,1});
    d[1][1]=0;
    a[1][1]=a[sx][sy]=1;
    while(!q.empty())
    {
        x=get<1>(q.top());
        y=get<2>(q.top());
        q.pop();
        if(vt[x][y]) continue;
        vt[x][y]=1;
        for(int i=0;i<4;i++)
        {
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]!=1) continue;
            if(d[nx][ny]>d[x][y]+1)
            {
                d[nx][ny]=d[x][y]+1;
                q.push({d[nx][ny],nx,ny});
            }
        }
    }
    if(d[sx][sy]==1e9) cout<<"cai jiu duo lian QAQ";
    else cout<<d[sx][sy]<<"\n";
    // for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
    // for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<d[i][j]<<" ";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}