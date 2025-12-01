#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b;
	cin>>a>>b;
	if(a>=b) cout<<a<<"\n";
	else if(2*a>=b) cout<<2*a-b<<"\n";
	else cout<<"0\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
