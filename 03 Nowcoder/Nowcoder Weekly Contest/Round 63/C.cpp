#include <bits/stdc++.h>
using namespace std;
int n,m,a[110][110],f[110][110];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			f[i][j]=0;
		}
	}
	f[1][1]=1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i-1>=1)
			{
				if(a[i][j]==a[i-1][j])
				f[i][j]|=f[i-1][j];
			}
			if(j-1>=1)
			{
				if(a[i][j-1]==a[i][j])
				f[i][j]|=f[i][j-1];
			}
		}
	}
	if(f[n][m]) cout<<"Yes\n";
	else cout<<"No\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
