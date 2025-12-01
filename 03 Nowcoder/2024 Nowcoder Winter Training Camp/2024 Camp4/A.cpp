#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int a,b,k;
	cin>>a>>b>>k;
	if(a>=k*b) cout<<"good\n";
	else cout<<"bad\n";

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
