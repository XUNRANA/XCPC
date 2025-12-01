#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,x;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>x;
		ans+=log2(x);
	}
	if(ans==0) cout<<"0\n";
	else cout<<ans/11+1<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
