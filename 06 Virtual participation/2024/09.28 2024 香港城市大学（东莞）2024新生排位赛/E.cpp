#include <bits/stdc++.h>
using namespace std;
void solve()
{
	long long a,b,c,d,ans;
	cin>>a>>b>>c>>d;
	ans=(a+29)/30+(b+29)/30+(c+29)/30+(d+29)/30;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
