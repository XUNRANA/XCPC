#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
void solve()
{
	cin>>n>>s;
	if(s[0]==s[s.size()-1]) cout<<"NO\n";
	else cout<<"YES\n";

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
