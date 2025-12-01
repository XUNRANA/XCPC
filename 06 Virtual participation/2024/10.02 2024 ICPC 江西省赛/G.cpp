#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char b;
		int a,c;
		cin>>a>>b;
		if(b=='A') c=0;
		else c=b-'0'; 
		s=(s+a*c%5)%5;
	}
	if(s==0) cout<<"Yes\n";
	else cout<<"No\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
