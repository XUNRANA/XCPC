#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1010][1010];
int l,r;
int d[1010][1010][2];
int vt[1010][1010][2];
int dx[]={0,0,-1,1,-1,1,1,-1};
int dy[]={-1,1,0,0,1,1,-1,-1};
void solve()
{
    cin>>n>>m;
    cin>>l>>r;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            vt[i][j][0]=vt[i][j][1]=0;
            d[i][j][0]=d[i][j][1]=1e18;
            a[i][j]=(ch=='1');
        }
    }
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    d[1][1][0]=0;
    q.push({0,1,1});
    while(!q.empty())
    {
        int w=q.top()[0];
        int x=q.top()[1];
        int y=q.top()[2];
        q.pop();
        if(vt[x][y][w&1]) continue;
        vt[x][y][w&1]=1;
        for(int i=0;i<8;i++) 
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||!a[nx][ny]) continue;
            if(d[nx][ny][(w+1)&1]>w+1)
            {
                d[nx][ny][(w+1)&1]=w+1;
                q.push({w+1,nx,ny});
            }
        }
    }

    if(d[n][m][0]==1e18&&d[n][m][1]==1e18) 
    {
        cout<<"-1\n";
        return ;
    }

    if(l!=r)
    {
        int ans=min(d[n][m][0],d[n][m][1]);
        cout<<(ans+r-1)/r<<"\n";
    }
    else
    {
        int ans=1e18;
        if(d[n][m][0]!=1e18)
        {
            int res=d[n][m][0]/l;
            d[n][m][0]%=l;
            if(!d[n][m][0]) ans=min(ans,res);
            else
            {
                //l : 5
                //:2 

                if((l-d[n][m][0])%2==0) ans=min(ans,res+1);
                else 
                {
                    if(l&1)  ans=min(ans,res+2);
                }
            }        
        }
        
        if(d[n][m][1]!=1e18)
        {
            int res=d[n][m][1]/l;
            d[n][m][1]%=l;
            if(!d[n][m][1]) ans=min(ans,res);
            else
            {
                //1 : 5
                if((l-d[n][m][1])%2==0) ans=min(ans,res+1);
                else 
                {
                    if(l&1) ans=min(ans,res+2);
                }
            }        
        }

        if(ans==1e18) ans=-1;
        cout<<ans<<"\n";
    }
    // for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<d[i][j][0]<<" ";

    // cout<<"\n";
    // for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<d[i][j][1]<<" ";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}