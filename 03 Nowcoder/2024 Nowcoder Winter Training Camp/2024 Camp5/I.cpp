#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,a,k;
void solve()
{
	cin>>t>>a>>k;
	if(a<=k&&a>=-k) cout<<abs(a)+abs(a-t)<<"\n";
    else if(a*t>=0&&abs(t)>=abs(a)) cout<<t<<"\n";
	else cout<<abs(t)+2*abs(t-a)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
