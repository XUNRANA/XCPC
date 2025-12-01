#include <bits/stdc++.h>
using namespace std;
int n,x,y,cnt;
char a[3][200010];
int f[3][200010];
void solve()
{
	cnt=0;
	cin>>n;
	for(int i=1;i<=2;i++) for(int j=1;j<=n;j++) cin>>a[i][j],f[i][j]=0;
	queue<pair<int,int>>q;
	q.push({1,1});
	while(!q.empty())
	{
		cnt++;
		x=q.front().first;
		y=q.front().second;
		q.pop();
		f[x][y]=1;
		if(y+2<=n&&a[x][y+1]=='>'&&!f[x][y+2]) q.push({x,y+2});
		if(x==1)
		{
			if(y+1<=n&&a[2][y]=='>'&&!f[2][y+1]) q.push({2,y+1});
		    if(y-1>=1&&a[2][y]=='<'&&!f[2][y-1]) q.push({2,y-1});
		}
		if(x==2)
		{
			if(y+1<=n&&a[1][y]=='>'&&!f[1][y+1]) q.push({1,y+1});
		    if(y-1>=1&&a[1][y]=='<'&&!f[1][y-1]) q.push({1,y-1});
		}
		if(f[2][n]) 
		{
			cout<<"YES\n";
			return ;
		}
		if(cnt>100*n) break;
	}
	//for(int i=1;i<=2;i++,cout<<"\n") for(int j=1;j<=n;j++) cout<<f[i][j]<<" ";
	cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
