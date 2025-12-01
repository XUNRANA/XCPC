#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	string s1,s2;
	cin>>s1>>s2;
	if(toupper(s1[0])==toupper(s2[0])) cout<<"Yes\n";
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
