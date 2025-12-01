#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int t;
	for(int i=1;i<=5;i++) 
	{
		cin>>t;
		if(t)
		{
			cout<<i<<"\n";
			return ;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
