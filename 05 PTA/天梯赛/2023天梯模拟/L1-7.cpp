#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n,m,q,x,y;
	
	cin>>n>>m>>q;
	vector<vector<int>>a(n+1,vector<int>(m+1,0));
	while(q--)
	{
		cin>>x>>y;
		if(!x) for(int i=1;i<=m;i++) a[y][i]=1;
		else for(int i=1;i<=n;i++) a[i][y]=1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!a[i][j]) cnt++;
	cout<<cnt<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
