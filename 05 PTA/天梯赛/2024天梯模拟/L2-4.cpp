#include <bits/stdc++.h>
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>a(n+2,vector<int>(m+2,0));
	vector<vector<int>>vt(n+2,vector<int>(m+2,0));
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
	{
		char ch;
		cin>>ch;
		a[i][j]=ch-'0';
	}
	int cnt=0,cnt1=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		if(!vt[i][j]&&a[i][j])
		{
			cnt++;
			queue<pair<int,int>>q;
			q.push({i,j});
			int f=0;
			while(!q.empty())
			{
				int x=q.front().first;
				int y=q.front().second;
				q.pop();
				if(vt[x][y]) continue;
				vt[x][y]=1;
				if(a[x][y]>=2&&a[x][y]<=9) f=1;
				for(int k=0;k<4;k++)
				{
					int nx=x+dx[k];
					int ny=y+dy[k];
					if(nx<1||nx>n||ny<1||ny>m||!a[nx][ny]) continue;
					q.push({nx,ny});
				}
			}
			if(f) cnt1++;
		}
	}
	cout<<cnt<<" "<<cnt1<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
