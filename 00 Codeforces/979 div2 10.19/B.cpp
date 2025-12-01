#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	string ans;
	cin>>n;
	for(int i=1;i<n;i++) 
	ans+='0';
	ans+='1';
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
