#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[510][510],dp[510][510],t,x,y,nx,ny,nt;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >q;
    q.push({a[1][1],{1,1}});
    while(!q.empty())
    {
        t=q.top().first;
        x=q.top().second.first;
        y=q.top().second.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            nx=x+dx[i];
            ny=y+dy[i];
        	nt=max(t,a[nx][ny]);
            if(nx>n||ny>n||nx<1||ny<1) continue;
            if(!dp[nx][ny]||nt<dp[nx][ny])
            {
                dp[nx][ny]=nt;
                q.push({nt,{nx,ny}});
            }
        }
    }
    cout<<dp[n][n]<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
