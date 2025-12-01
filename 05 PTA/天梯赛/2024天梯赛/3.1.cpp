#include <bits/stdc++.h>
using namespace std;
int n,m,a[110][110],x,y,d,nx,ny;
int ans[110][110];
int vt[110][110];
int dx[]={-1,1,0,0};
vector<int>g[220];
int dy[]={0,0,-1,1};
#define N 999999
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans[i][j]=N;
			cin>>a[i][j];
			if(a[i][j]==2) 
			{
				x=i;
				y=j;
			}
		}
	}
	
	priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>> > >q;
	q.push({0,{x,y}});
	while(q.size())
	{
		d=q.top().first;
		x=q.top().second.first;
		y=q.top().second.second;
	//	cout<<x<<" "<<y<<" "<<d<<"\n";
		q.pop();
		if(a[x][y]==0) continue;
		ans[x][y]=min(ans[x][y],d);
		vt[x][y]=1;
		for(int i=0;i<4;i++)
		{
			nx=x+dx[i];
			ny=y+dy[i];
			if(vt[nx][ny]) continue;
			q.push({d+1,{nx,ny}});
		}
	}
	
	for(int i=1;i<=m;i++,cout<<"\n")
	for(int j=1;j<=n;j++) cout<<ans[i][j]<<" ";
	

	int q1;
	cin>>q1;
	for(int i=1;i<=q1;i++)
	{
		cin>>x>>y;
		//cout<<y<<" "<<x<<" "<<ans[y][x]<<"\n";
		if(ans[y][x]==N) continue;
		else g[ans[y][x]].push_back(i);
	}
	
	int f=0;
	for(int i=0;i<=200;i++) 
	if(g[i].size()==1) 
	{
		cout<<g[i][0]<<" "<<i<<"\n";
		return 0;
	}
	cout<<"No winner.";
}
