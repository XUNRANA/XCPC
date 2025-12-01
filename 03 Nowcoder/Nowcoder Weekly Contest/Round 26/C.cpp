#include <bits/stdc++.h>
using namespace std;
int n,m,a[2010][2010],dp[2010][2010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) dp[i][j]=1e9;
	dp[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=min({dp[i][j],dp[i][j-1]+1+(a[i][j-1]!=a[i][j]),dp[i-1][j]+1+(a[i-1][j]!=a[i][j])});
		}
		for(int j=m;j>=1;j--)
		{
			dp[i][j]=min({dp[i][j],dp[i][j+1]+1+(a[i][j+1]!=a[i][j]),dp[i-1][j]+1+(a[i-1][j]!=a[i][j])});
		}
	}
	//for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<dp[i][j]<<" ";
	cout<<dp[n][m]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}














/*

#include <bits/stdc++.h>
using namespace std;
int n,m,a[2010][2010],d[2010][2010];
int dx[]={0,0,1};
int dy[]={-1,1,0};
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j],d[i][j]=1e9;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,less<pair<int,pair<int,int>>>>q;
	q.push({0,{1,1}});
	d[1][1]=0;
	while(!q.empty())
	{
		int w=q.top().first;
		int x=q.top().second.first;
		int y=q.top().second.second;
		q.pop();
		for(int i=0;i<3;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nw=w;
			if(nx<1||nx>n||ny<1||ny>m) continue;
			
			if(a[x][y]==a[nx][ny]) nw++;
			else nw+=2;
			if(d[nx][ny]>nw) 
			{
				d[nx][ny]=nw;
				q.push({d[nx][ny],{nx,ny}});
			}
		} 
	}
	cout<<d[n][m]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

*/

