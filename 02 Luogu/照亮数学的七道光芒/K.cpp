#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
struct node{int x,y,s,t,d;};
queue<node>q;
char a[110][110];
int n,m,v[110][110][5][2],ans;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve()
{
	cin>>n>>m;
	ans=inf;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int d=0;d<4;d++) v[i][j][d][0]=v[i][j][d][1]=inf;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	q.push((node){1,1,0,0,5});
	while(q.size())
	{
		node f=q.front();
		q.pop();
		if(f.s>m||f.t>=ans) continue;
		if(f.s>=v[f.x][f.y][f.d][0]&&f.t>=v[f.x][f.y][f.d][1]) continue;
		v[f.x][f.y][f.d][0]=min(f.s,v[f.x][f.y][f.d][0]);
		v[f.x][f.y][f.d][1]=min(f.t,v[f.x][f.y][f.d][1]);
		if(f.x==n&&f.y==n)
		{
			ans=min(ans,f.t);
			continue;
		}
		for(int i=0;i<4;i++)
		{
			int nx=f.x+dx[i],ny=f.y+dy[i];
			if(nx<1||nx>n||ny>n||ny<1||a[nx][ny]=='*') continue;
			q.push((node){nx,ny,i==f.d?f.s+1:1,f.t+1,i});
		}
	}
	if(ans>=inf) cout<<"-1\n";
	else cout<<ans<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--) solve();
} 
