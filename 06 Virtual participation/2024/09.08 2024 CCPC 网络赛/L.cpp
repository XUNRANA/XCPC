#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
char a[510][510];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			if(a[i][j]=='p'&&a[i-1][j]=='c'&&a[i-1][j+1]=='c'&&a[i][j+1]=='c') ans++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
