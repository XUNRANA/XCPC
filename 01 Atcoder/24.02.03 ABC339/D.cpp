#include <bits/stdc++.h>
using namespace std;
int x1,x2,y11,y2,nx1,ny1,nx2,ny2,n,ans=1e9;
char s[65][65];
int f[65][65][65][65];
int d[65][65][65][65];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
queue<pair<pair<int,int>,pair<int,int>>>q;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	{
		cin>>s[i][j];
		if(s[i][j]=='P')
		{
			if(!x1) x1=i,y11=j;
			else x2=i,y2=j;
		}
	}
	q.push({{x1,y11},{x2,y2}});
	f[x1][y11][x2][y2]=1;
	memset(d,0x3f,sizeof(d));
	d[x1][y11][x2][y2]=0;
	while(!q.empty())
	{
		x1=q.front().first.first;
		y11=q.front().first.second;
		x2=q.front().second.first;
		y2=q.front().second.second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			nx1=x1+dx[i];
			ny1=y11+dy[i];
			nx2=x2+dx[i];
			ny2=y2+dy[i];
			if(nx1==0) nx1=1;
			if(ny1==0) ny1=1;
			if(nx2==0) nx2=1;
			if(ny2==0) ny2=1;
			
			if(nx1==n+1) nx1=n;
			if(ny1==n+1) ny1=n;
			if(nx2==n+1) nx2=n;
			if(ny2==n+1) ny2=n;
			if(s[nx1][ny1]=='#') nx1=x1,ny1=y11;
			if(s[nx2][ny2]=='#') nx2=x2,ny2=y2;
			
			if(f[nx1][ny1][nx2][ny2]) continue;
			if(x1==nx1&&x2==nx2&&y11==ny1&&y2==ny2) continue;
			f[nx1][ny1][nx2][ny2]=1;
			d[nx1][ny1][nx2][ny2]=d[x1][y11][x2][y2]+1;
			q.push({{nx1,ny1},{nx2,ny2}});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans=min(ans,d[i][j][i][j]);
	if(ans==1e9) ans=-1;
	cout<<ans;
} 
int main()
{
	int t;
	t=1;
	//cin>>t;
	while(t--) solve();
}
