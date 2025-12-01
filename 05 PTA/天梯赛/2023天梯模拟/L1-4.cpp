#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b;
	cin>>a>>b;
	int ans=1;
	for(int i=1;i<=a+b;i++) ans*=i;
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
