#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010][1010];
int n,m;
int dx[]={0,0,-1,1,-1,-1,1,1,0,0,-2,2};
int dy[]={-1,1,0,0,-1,1,-1,1,-2,2,0,0};
void fx1(int i,int j)
{
	a[i][j]=1;
	for(int k=0;k<4;k++)
	{
		int ni=dx[k]+i;
		int nj=dy[k]+j;
		if(ni<1||ni>n||nj<1||nj>m) continue;
		a[ni][nj]=1;
	}
}
void fx2(int i,int j)
{
	a[i][j]=1;
	for(int k=0;k<12;k++)
	{
		int ni=dx[k]+i;
		int nj=dy[k]+j;
		if(ni<1||ni>n||nj<1||nj>m) continue;
		a[ni][nj]=1;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='*') fx1(i,j);
			else if(ch=='#') fx2(i,j);
		}
	}
	int ans=0;
	// for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans+=(a[i][j]==0);
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}  
