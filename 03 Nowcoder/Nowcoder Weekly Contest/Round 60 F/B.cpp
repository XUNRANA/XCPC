#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x,y;
	cin>>x>>y;
	if(abs(x-y)<=1) cout<<x+y<<"\n";
	else cout<<2*min(x,y)+1<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
