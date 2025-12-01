#include <bits/stdc++.h>
using namespace std;

int n,m,a[1010][1010];
int vt[1010][1010][2];
int d[1010][1010];
int vis[1010][1010];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void bfs(int x,int y,int f)
{
    queue<array<int,2>>q;
    q.push({x,y});
    vt[x][y][f]=1;
    while(!q.empty())
    {
        int x=q.front()[0];
        int y=q.front()[1];
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]==0) continue;
            if(!vt[nx][ny][f])
            {
                vt[nx][ny][f]=1;
                q.push({nx,ny});
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

            d[i][j]=1e9;
            vis[i][j]=0;
            
            a[i][j]=(ch=='.');
            vt[i][j][0]=vt[i][j][1]=0;
        }
    }

    bfs(1,1,0);
    bfs(n,m,1);

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    if(vt[i][j][0]&&vt[i][j][1])
    {
        cout<<"0\n";
        return ;
    }

    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vt[i][j][0])
            {
                d[i][j]=0;
                q.push({0,i,j});
            }
        }
    }

    
    while(!q.empty())
    {
        int w=q.top()[0];
        int x=q.top()[1];
        int y=q.top()[2];
        q.pop();

        
        if(vt[x][y][1])
        {
            cout<<w-1<<"\n";
            return ;
        }

        if(vis[x][y]) continue;
        vis[x][y]=1;

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m) continue;

            if(d[nx][ny]>d[x][y]+1)
            {
                d[nx][ny]=d[x][y]+1;
                q.push({d[nx][ny],nx,ny});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}

