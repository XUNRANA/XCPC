#include <bits/stdc++.h>
using namespace std;

int a[110][110];
vector<int>g[210];
int d[110][110];
int vt[110][110];
int n,m,nq,sx,sy,x,y;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==2)
			{
				sx=i;
				sy=j;
			}
		}
	}
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) d[i][j]=1e9;
	queue<pair<int,int>>q;
	q.push({sx,sy});
	d[sx][sy]=0;
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		q.pop();
		if(x<1||x>n||y<1||y>m||vt[x][y]) continue;
		vt[x][y]=1;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(a[nx][ny]!=1) continue;
			if(d[nx][ny]>d[x][y]+1)
			{
				d[nx][ny]=d[x][y]+1;
				q.push({nx,ny});
			} 
		}
	}
//	for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<d[i][j]<<" "; 
	
	cin>>nq;
	for(int i=1;i<=nq;i++)
	{
		cin>>y>>x;
//		cout<<i<<" "<<d[x][y]<<"\n";
		if(d[x][y]!=1e9) g[d[x][y]].push_back(i);
	}
	
	for(int i=1;i<=n+m;i++) 
	{
		if(g[i].size()==1)
		{
			cout<<g[i][0]<<" "<<i<<"\n";
			return ;
		}
	}
	cout<<"No winner.\n";

} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

