#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b;
	cin>>a>>b;
	int ans=0;
	if(b==2) ans+=(2-a)*2+2;
	else ans+=(2-a)+2;
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
