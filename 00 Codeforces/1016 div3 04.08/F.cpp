#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<string>a(n+1);
	vector<vector<string>>b(m+1,vector<string>(n+1));

	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) cin>>b[i][j];
	
	for(int j=1;j<=n;j++)
	{
		int f=0;
		for(int i=1;i<=m;i++) if(b[i][j]==a[j]) f=1;
		if(!f)
		{
			cout<<"-1\n";
			return ;
		}
	}
	int mx=0;
	for(int i=1;i<=m;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++) cnt+=(a[j]==b[i][j]);
		mx=max(mx,cnt);
	}
	cout<<3*n-2*mx<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

