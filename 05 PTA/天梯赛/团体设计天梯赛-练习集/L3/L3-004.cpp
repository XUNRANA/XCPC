#include <bits/stdc++.h>
using namespace std;
int cnt;
int ans;
int dx[]={0,0,0,0,1,-1};
int dy[]={0,0,1,-1,0,0};
int dz[]={1,-1,0,0,0,0};
int n,m,l,t;
void dfs(int x,int y,int z,vector<vector<vector<int>>>&a,vector<vector<vector<int>>>&vt)
{
	queue< pair<pair<int,int>,int> >q;
	q.push({{x,y},z});
	while(!q.empty())
	{
		x=q.front().first.first;
		y=q.front().first.second;
		z=q.front().second;
		q.pop();
		if(vt[x][y][z]) continue;
		vt[x][y][z]=1;
		cnt++;
		for(int i=0;i<6;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nz=z+dz[i];
			if(nx<1||nx>n||ny<1||ny>m||nz<1||nz>l||!a[nx][ny][nz]) continue;
			q.push({{nx,ny},nz});
		}
	}
}
void solve()
{
	cin>>n>>m>>l>>t;
    vector<vector<vector<int>>>a(n+2,vector<vector<int>>(m+2,vector<int>(l+2,0)));
    vector<vector<vector<int>>>vt(n+2,vector<vector<int>>(m+2,vector<int>(l+2,0)));
	for(int k=1;k<=l;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j][k];
			}
		}
	}
	
	for(int k=1;k<=l;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(!vt[i][j][k]&&a[i][j][k])
				{
					cnt=0;
					dfs(i,j,k,a,vt);
//					cout<<cnt<<"\n";
					if(cnt>=t) ans+=cnt;
				}
			}
		}
	}
	
	cout<<ans<<"\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}


