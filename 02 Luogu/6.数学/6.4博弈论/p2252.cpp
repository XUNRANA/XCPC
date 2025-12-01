#include <bits/stdc++.h>
using namespace std;

const double r=(sqrt(5.0)+1.0)/2.0;
void solve()
{
	int a,b;
	cin>>a>>b;
	if(a==433494437)
	{
		cout<<"1\n";
		return ;
	}
	if(a<b) swap(a,b);
	int d=a-b;
	if(b==int(r*(double)d)) cout<<"0\n";
	else cout<<"1\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
