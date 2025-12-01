#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p,inv[3000010];
void init(int n)
{
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=1ll*(p-p/i)*inv[p%i]%p;//线性求逆元 
}
void solve()
{
	cin>>n>>p;
	init(n);
	for(int i=1;i<=n;i++) cout<<inv[i]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
