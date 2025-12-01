#include <bits/stdc++.h>
using namespace std;
long long n,t;
long long ans;
void solve()
{
    ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		ans+=(t+2)*(t+2)-4;
	}                    
	cout<<ans+10<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
