#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int cnt=1,ans=0;
	while(n)
	{
		ans+=cnt;
		n/=2;
		cnt*=2;
	}
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
