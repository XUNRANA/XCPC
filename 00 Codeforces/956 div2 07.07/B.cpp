#include <bits/stdc++.h>
using namespace std;
int n,m;
char a[510][510];
int b[501][510];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		char t;
		cin>>t;
		b[i][j]=(t-a[i][j]+3)%3;
	}
	for(int i=1;i<=n;i++)
	{
		int s=0;
		for(int j=1;j<=m;j++)
		{
			s+=b[i][j];
		}
		if(s%3!=0)
		{
			cout<<"NO\n";
			return ;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int s=0;
		for(int j=1;j<=n;j++)
		{
			s+=b[j][i];
		}
		if(s%3!=0)
		{
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
