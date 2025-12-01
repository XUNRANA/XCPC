#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v={{0,-1},{0,1},{-1,0},{1,0}};
int n,m,ni,nj,a[110][110];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) a[i][j]=0; 
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int mx=0;
			for(int k=0;k<4;k++)
			{
				ni=i+v[k].first;
				nj=j+v[k].second;
				mx=max(mx,a[ni][nj]);
			}
			if(mx<a[i][j]) a[i][j]=mx;
		}
	}
	for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
