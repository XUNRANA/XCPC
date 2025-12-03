#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x1,y11,x2,y2,x,y;
int a[1011][1011];
int b[1011][1011];
int vt[1011][1011];
int d[1011][1011];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve()
{
    cin>>n>>x1>>y11>>x2>>y2;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        b[x][y]=1;
    }
    for(int i=0;i<=1001;i++) for(int j=0;j<=1001;j++) d[i][j]=1e9;
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    q.push({0,x1,y11});
    d[x1][y11]=0;
    while(!q.empty())
    {
        auto t=q.top();
        q.pop();
        int dis=t[0];
        int x=t[1];
        int y=t[2];
        if(vt[x][y]) continue;
        vt[x][y]=1;
        if(x==x2&&y==y2)
        {
            cout<<dis<<"\n";
            return;
        }
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>1001||ny<0||ny>1001) continue;
            int nd=dis+b[nx][ny];
            if(nd<d[nx][ny]) 
            {
                d[nx][ny]=nd;
                q.push({nd,nx,ny});
            }
        }
    }
    cout<<d[x2][y2]<<"\n";
} 

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
