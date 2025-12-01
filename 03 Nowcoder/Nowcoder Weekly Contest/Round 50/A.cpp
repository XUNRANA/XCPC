#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,x;
void solve()
{
	cin>>a>>b>>x;
    if(abs(a-b)>=x) cout<<"NO\n";
    else cout<<"YES\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
