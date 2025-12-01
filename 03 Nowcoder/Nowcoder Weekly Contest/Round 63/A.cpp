#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x;
	cin>>x;
	if(x>=10&&x<=99&&x%10==x/10) cout<<"Yes\n";
	else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
