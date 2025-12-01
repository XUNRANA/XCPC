#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int sx,sy,tx,ty;
char a[210][210];
int d[210][210][2];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void solve()
{
    cin>>n>>m;
    vector<array<int,2>>v;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            d[i][j][0]=d[i][j][1]=1e9;
            if(a[i][j]=='S') 
            {
                sx=i;
                sy=j;
            }
            else if(a[i][j]=='P') 
            {
                tx=i;
                ty=j;
            } 
            else if(a[i][j]=='@') v.push_back({i,j});
        }
    }
    queue<array<int,3>>q;
    q.push({sx,sy,0});
    d[sx][sy][0]=0;
    while(!q.empty())
    {
        int x=q.front()[0];
        int y=q.front()[1];
        int s=q.front()[2];
        q.pop();
        if(a[x][y]=='@'&&s==0)
        {
            for(auto i:v)
            {
                int nx=i[0];
                int ny=i[1];
                if(nx==x&&ny==y) continue;
                if(d[nx][ny][1]>d[x][y][s])
                {
                    d[nx][ny][1]=d[x][y][s];
                    q.push({nx,ny,1});
                }
            }
        }
        else
        {  
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='#') continue;
                if(d[nx][ny][s]>d[x][y][s]+1)
                {
                    d[nx][ny][s]=d[x][y][s]+1;
                    q.push({nx,ny,s});
                }
            }
        }   
    }
    int ans=min(d[tx][ty][0],d[tx][ty][1]);
    if(ans==1e9) ans=-1;
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
