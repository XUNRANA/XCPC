#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<int>>vt(n+1,vector<int>(m+1,0));
	while(q--)
	{
		int t,c;
		cin>>t>>c;
		if(t==0) for(int i=1;i<=m;i++) vt[c][i]=1;
		else for(int i=1;i<=n;i++) vt[i][c]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans+=(vt[i][j]==0);
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

