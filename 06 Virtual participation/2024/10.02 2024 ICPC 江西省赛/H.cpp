#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[1010][1010],b[1010][1010];
int n,m,k,l;
int get(int x,int y,int x1,int y1)
{
	return b[x1][y1]-b[x-1][y1]-b[x1][y-1]+b[x-1][y-1];
}
void solve()
{
	cin>>n>>m>>k>>l;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>a[i][j];
		b[i][j]=a[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
	}
	vector<int>v;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=l;j++)
		{
			v.push_back(get(i,j,n-k+i,m-l+j));
		}
	}
	int ans=0;
	for(auto i:v) ans+=abs(i);
	cout<<ans<<"\n";
	/*
	 5 5 3 3
 0 -1 -1 0 0
 0  1 -1 2-2
 2 -2 2 2 0
 -1 0 0 -2-1
 0 -2 0 1 1
	*/
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
