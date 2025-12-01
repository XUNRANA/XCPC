#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<k;i++)
	{
		int j=k-i;
		if(n-i>=1&&m-j>=1) ans+=(n-i)*(m-j);
	}
	ans*=2;
	if(n-k>=1) ans+=(n-k)*m;
	if(m-k>=1) ans+=(m-k)*n;
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
