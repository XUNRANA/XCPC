#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,ans[1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(!t) ans[i]=1;
		else ans[i]=t*t-t+2;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
