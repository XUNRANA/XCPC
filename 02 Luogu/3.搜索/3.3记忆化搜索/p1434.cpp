#include <bits/stdc++.h>
using namespace std;
int r,c,ans,a[110][110],f[110][110];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int dfs(int x,int y)
{
	if(f[x][y]) return f[x][y];
	f[x][y]=1;
    for(int i=0;i<4;i++) 
	{
		if(x+dx[i]>=1&&x+dx[i]<=r&&y+dy[i]>=1&&y+dy[i]<=c&&a[x][y]>a[x+dx[i]][y+dy[i]])
		{
			dfs(x+dx[i],y+dy[i]);
			f[x][y]=max(f[x][y],f[x+dx[i]][y+dy[i]]+1);
		}
	}
	return f[x][y];
}
int main()
{
	cin>>r>>c;
	for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) cin>>a[i][j];
	for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) ans=max(ans,dfs(i,j));	
	cout<<ans;
}
