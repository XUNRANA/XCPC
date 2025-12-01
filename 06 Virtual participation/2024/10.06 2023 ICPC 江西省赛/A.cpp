#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,s,v;
	cin>>n>>s>>v;
	if(s*v>=n) cout<<"1";
	else cout<<"0";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
