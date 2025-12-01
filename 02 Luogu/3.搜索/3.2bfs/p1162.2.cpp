#include <bits/stdc++.h>
using namespace std;
int n,a[32][32];
void dfs(int x,int y)
{
	if(x<0||x>n+1||y<0||y>n+1||a[x][y]) return ;
	a[x][y]=2;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	dfs(0,0);
	for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=n;j++)
	if(a[i][j]==2) cout<<0<<" ";
	else if(a[i][j]==0) cout<<2<<" ";
	else cout<<1<<" ";
}
