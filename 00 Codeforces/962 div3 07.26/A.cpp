#include <bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
	int n;
	cin>>n;
	if(n%4==0) cout<<n/4<<"\n";
	else cout<<n/4+1<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
