#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int x,y,k;
	cin>>x>>y>>k;
	x=min(x,y);
	cout<<0<<" "<<0<<" "<<x<<" "<<x<<"\n";
	cout<<x<<" "<<0<<" "<<0<<" "<<x<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
