#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,h,ans;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void solve()
{
    cin>>n>>m>>h;
    vector<vector<char>>a(n+1,vector<char>(m+1));
    vector<vector<int>>dis(n+1,vector<int>(m+1,1e9));
    vector<vector<int>>vt(n+1,vector<int>(m+1,0));
    int x,y;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
    {
        cin>>a[i][j];
        if(a[i][j]=='S')
        {
            x=i;
            y=j;
        }
    }
  //  for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<char(a[i][j]);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    q.push({0,{x,y}});
    dis[x][y]=0;
    ans=1e9;
    while(!q.empty())
    {
        int d=q.top().first;        
        int x=q.top().second.first;
        int y=q.top().second.second;
        q.pop();
        if(vt[x][y]) continue;
        vt[x][y]=1;
      //  cout<<x<<" "<<y<<" "<<d<<"\n";
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||vt[nx][ny]) continue;
            if(a[nx][ny]=='T')
            {
              //  cout<<x<<" "<<y<<" "<<d<<"\n";
                ans=min(ans,d);
                continue;
            }
            if(dis[x][y]+a[nx][ny]-'0'<dis[nx][ny])
            {
                dis[nx][ny]=dis[x][y]+a[nx][ny]-'0';
                q.push({dis[nx][ny],{nx,ny}});
            }
        }
    }
    if(ans<h) cout<<"Yes\n";
    else cout<<"No\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

