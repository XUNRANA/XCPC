#include <bits/stdc++.h>
using namespace std;
char a[510][510];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
char b[]={'D','U','R','L'};
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i][j]=='.')
		{
			if(i!=1||j!=m)
			{
				cout<<"No\n";
				return ;
			}
		}
	}
	if(a[1][m]!='.')
	{
		cout<<"No\n";
		return ;
	}
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i][j]=='U'&&i-1>=1)
		{
			if(a[i-1][j]!='C')
			{
				cout<<"No\n";
				return ;
			}
		}
		if(a[i][j]=='D'&&i+1<=n)
		{
			if(a[i+1][j]!='C')
			{
				cout<<"No\n";
				return ;
			}
		}
		if(a[i][j]=='L'&&j-1>=1)
		{
			if(a[i][j-1]!='C')
			{
				cout<<"No\n";
				return ;
			}
		}
		if(a[i][j]=='R'&&j+1<=m)
		{
			if(a[i][j+1]!='C')
			{
				cout<<"No\n";
				return ;
			}
		}
		if(a[i][j]=='C')
		{
			int cnt=0;
			for(int k=0;k<4;k++)
			{
				int ni=i+dx[k];
				int nj=j+dy[k];
				if(ni<1||ni>n||nj<1||nj>m) continue;
//				cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<" "<<b[k]<<"\n";
				if(a[ni][nj]==b[k]) cnt++;
			}
			if(cnt!=2) 
			{
				cout<<"No\n";
				return ;
			}
		}
	}
	cout<<"Yes\n";
}
/*
2
4 4
CLD.
UDCL
DCLD
CLRC
2 3
DRC
CLU
*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
