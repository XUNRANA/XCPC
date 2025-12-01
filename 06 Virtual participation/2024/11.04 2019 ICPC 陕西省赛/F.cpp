#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007


void solve()
{
	int x,y,z;
	cin>>x>>y>>z;
	
	if(x+y==z) 
	{
		cout<<z+1<<"\n";
		return ;
	}
	
	int k=x+y-z;
	if(k<=1||x>k||z>k) cout<<"-1\n";
	else cout<<k<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
