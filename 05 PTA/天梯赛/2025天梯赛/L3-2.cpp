#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int fx(int x,int y)
{
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans=ans+max(abs(i-x),abs(j-y));
	return ans;
}
void solve()
{
	cin>>n>>m;
	vector<vector<int>>a(n+1,vector<int>(m+1,0));
	
	vector<vector<int>>ans(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			ans[i][j]=fx(i,j);
		}
	}
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cout<<ans[i][j]*a[i][j]<<" \n"[j==m];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
