#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r;
void solve()
{
	cin>>n;
	int ans=1e9; 
	for(int i=1;i<=n;i++) 
	{
		cin>>l>>r;
		ans=min(ans,r-1);
		if(l!=1) ans=min(ans,l-1);
	}
	cout<<ans<<" "<<2*n-1<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

