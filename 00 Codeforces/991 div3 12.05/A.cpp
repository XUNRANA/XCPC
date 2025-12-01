#include <bits/stdc++.h>
using namespace std;
#define int long long
string s[51];
void solve()
{
	int n,m,cnt=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		cnt+=s[i].size();
		if(cnt>m) break;
		ans++;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
