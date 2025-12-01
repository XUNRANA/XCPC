#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,u,v;
string s;
void solve()
{
	cin>>k;
	cin>>s;
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>u>>v;
	int d=m-(n-1);
	if(s[d%k]=='1') cout<<"2\n";
	else cout<<"1\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
