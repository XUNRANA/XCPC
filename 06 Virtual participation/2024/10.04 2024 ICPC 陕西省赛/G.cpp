#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,x;
	cin>>n>>x;
	int pre=1,sum=1;
	while(n)
	{
		int y=n%10;
		if(y>x) y--;
		sum+=y*pre;
		pre=pre*9;
		n/=10;
	}
	cout<<sum<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
