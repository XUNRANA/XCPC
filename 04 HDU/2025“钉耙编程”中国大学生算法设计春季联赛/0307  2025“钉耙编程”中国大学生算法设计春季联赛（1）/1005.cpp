#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve()
{
	cin>>n>>m;
	vector<vector<int>>t(n+1,vector<int>(m+1));
	vector<vector<int>>d(n+1,vector<int>(m+1));
	vector<vector<vector<int>>> dis(n+1,vector<vector<int>>(m+1,vector<int>(4,1e18)));
	vector<vector<vector<int>>> vt(n+1,vector<vector<int>>(m+1,vector<int>(4,0)));
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>t[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>d[i][j];
	priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>> >q;
	dis[1][1][3]=t[1][1];
	q.emplace(dis[1][1][3],1,1,3);
	dis[1][1][0]=dis[1][1][1]=dis[1][1][2]=t[1][1]+d[1][1];
	q.emplace(dis[1][1][0],1,1,0);
	q.emplace(dis[1][1][1],1,1,1);
	q.emplace(dis[1][1][2],1,1,2);
	while(!q.empty())
	{
		int di=get<0>(q.top());
		int type=get<3>(q.top());
		int x=get<1>(q.top());
		int y=get<2>(q.top());
		q.pop();
		if(vt[x][y][type]) continue;
		vt[x][y][type]=1;

			int nx=x+dx[type];
			int ny=y+dy[type];
			if(nx<1||nx>n||ny<1||ny>m) continue;
			
			
			for(int j=0;j<4;j++)
			{
				if(j==type) 
				{
					if(di+t[nx][ny]<dis[nx][ny][j])
					{
						dis[nx][ny][j]=di+t[nx][ny];
						q.emplace(dis[nx][ny][j],nx,ny,j);
					}
				}
				else 
				{
					if(di+t[nx][ny]+d[nx][ny]<dis[nx][ny][j])
					{
						dis[nx][ny][j]=di+t[nx][ny]+d[nx][ny];
						q.emplace(dis[nx][ny][j],nx,ny,j);
					}
				}
			} 
	}
	cout<<dis[n][m][1]<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

