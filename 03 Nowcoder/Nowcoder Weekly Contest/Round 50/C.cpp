#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c;
void solve()
{
    cin>>a>>b>>c;
    cout<<max({a*b*c,(a+b)*c,a*(b+c),a+b+c});
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
