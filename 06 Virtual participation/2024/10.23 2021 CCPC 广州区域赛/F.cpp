#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,f[300010];
void solve()
{
	cin>>n;
	f[1]=f[2]=1;
	for(int i=3;i<=n;i++) f[i]=(f[i-1]+f[i-2])%P;
	cout<<f[n];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
