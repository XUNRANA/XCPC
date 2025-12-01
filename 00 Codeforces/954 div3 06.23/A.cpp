#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x1,x2,x3;
	cin>>x1>>x2>>x3;
	cout<<max({x1,x2,x3})-min({x1,x2,x3})<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
