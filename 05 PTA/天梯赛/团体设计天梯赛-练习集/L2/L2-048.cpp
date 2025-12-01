#include <bits/stdc++.h>
using namespace std;
int f;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void bfs(int x,int y,vector<vector<int>>&a,vector<vector<int>>&vt)
{
	queue<pair<int,int>>q;
	q.push({x,y});
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		q.pop();
		if(vt[x][y]||!a[x][y]) continue;
		vt[x][y]=1;
		if(a[x][y]&&a[x][y]!=1) f=1;
		for(int i=0;i<4;i++) 
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			q.push({nx,ny});
		}
	}
}
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>a(n+2,vector<int>(m+2,0));
	vector<vector<int>>vt(n+2,vector<int>(m+2,0));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		char ch;
		cin>>ch;
		a[i][j]=ch-'0';
	}
	
	int cnt=0,cnt1=0;
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++) 
	if(!vt[i][j]&&a[i][j])
	{
		cnt++;
		f=0;
		bfs(i,j,a,vt);
		if(f) cnt1++;
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

