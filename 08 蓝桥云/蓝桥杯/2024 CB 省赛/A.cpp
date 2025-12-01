#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int ans=0;
	for(int i=7;i<=49;i++) ans+=i;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
