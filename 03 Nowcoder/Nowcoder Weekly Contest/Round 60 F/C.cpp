#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,m,x,y,ans;
vector<int>g[N][2];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		g[x][0].push_back(y);
		g[y][1].push_back(x);
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		sort(g[i][1].begin(),g[i][1].end());
		sort(g[i][0].begin(),g[i][0].end());
		if(g[i][1].size()>=2) ans=max(ans,g[i][1].back()-g[i][1][0]);
		if(g[i][0].size()>=2) ans=max(ans,g[i][0].back()-g[i][0][0]);
	}
	cout<<ans<<"\n";	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
