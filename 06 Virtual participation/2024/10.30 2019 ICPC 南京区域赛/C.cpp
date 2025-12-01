#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int dp[1010][1010][5];
int b[1010][1010];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void solve()
{
	int n,m;
	cin>>n>>m;
	map<int,vector<pair<int,int>> >mp;
	vector<int>a;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>b[i][j];
			a.push_back(b[i][j]);
			mp[b[i][j]].push_back({i,j});
		}
	}
		
	sort(a.begin(),a.end()); 
	vector<int>a1;
	a1.push_back(a[0]);
	for(int i=1;i<a.size();i++) if(a[i]!=a[i-1]) a1.push_back(a[i]);
	a=a1;
	sort(a.begin(),a.end(),greater<int>());
	
	for(auto i:mp[a[0]]) dp[i.first][i.second][1]=1;
	
	for(int i=1;i<a.size();i++)
	{
		for(auto j:mp[a[i]])
		{
			int x=j.first;
			int y=j.second;
			int f=0;
			for(int k=0;k<4;k++)
			{
				int nx=x+dx[k];
				int ny=y+dy[k];
				if(nx<1||nx>n||ny<1||ny>m) continue;
				if(b[nx][ny]==a[i]+1)
				{
					f=1;
					for(int k1=2;k1<=4;k1++)
					{
						dp[x][y][k1]+=dp[nx][ny][k1-1];
						dp[x][y][k1]%=P;
					}
					dp[x][y][4]+=dp[nx][ny][4];
					dp[x][y][4]%=P;
				}
			}
			
			if(!f) dp[x][y][1]=1;
		}
	}
	
//	for(int k=1;k<=4;k++)
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			
//			cout<<dp[i][j][k]<<" ";
//		}
//		cout<<"\n";
//	}
//	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int f=0;
			for(int k=0;k<4;k++)
			{
				int nx=i+dx[k];
				int ny=j+dy[k];
				if(nx<1||nx>n||ny<1||ny>m) continue;
				if(b[nx][ny]==b[i][j]-1)
				{
					f=1;
					break;
				}
			}
			if(!f) 
			{	 
				ans=(ans+dp[i][j][4])%P;
			}
		}
	}
	cout<<ans<<"\n";
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
