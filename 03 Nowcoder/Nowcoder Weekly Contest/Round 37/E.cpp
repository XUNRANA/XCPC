#include <bits/stdc++.h>
using namespace std;
#define int long long

char a[1010][1010];
int n,m,x,y;
int vt[1010][1010][4];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<4;k++) vt[i][j][k]=0;
	
			cin>>a[i][j];
			if(a[i][j]=='S')
			{
				x=i;
				y=j;
			}
		}
	}
	queue<pair<int,pair<int,pair<int,int>>>>q;
	q.push({0,{0,{x,y}}});//? 
	q.push({0,{1,{x,y}}});//? 
	q.push({0,{2,{x,y}}});//? 
	q.push({0,{3,{x,y}}});//?
	while(!q.empty())
	{
		int w=q.front().first;
		int i=q.front().second.first;
		int x=q.front().second.second.first;
		int y=q.front().second.second.second;
		q.pop();
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(vt[x][y][i]) continue;
		vt[x][y][i]=1;
		if(nx<1||nx>n||ny<1||ny>m) continue;
		if(a[nx][ny]=='T')
		{
			cout<<w+1<<"\n";
			return ;
		}
		if(a[nx][ny]!='#')
		{
			if(a[nx][ny]=='*')
			{
				for(int j=0;j<4;j++)
				{
					if((i^j)==1) continue;
					q.push({w+1,{j,{nx,ny}}});
				}
			}
			else q.push({w+1,{i,{nx,ny}}});
		}	
	}
	cout<<"-1\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

