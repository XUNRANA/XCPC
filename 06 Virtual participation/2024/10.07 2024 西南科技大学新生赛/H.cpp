#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int f[100010],n,ans;
int pre1[100010];
int pre2[100010];
void init()
{
	f[1]=f[2]=1;
	for(int i=3;i<=100000;i++) f[i]=(f[i-1]+f[i-2])%P;
	for(int i=1;i<=100000;i++) pre1[i]=(pre1[i-1]+f[i])%P;
	for(int i=1;i<=100000;i++) pre2[i]=(pre2[i-1]+f[i]*f[i]%P)%P;
}
void solve()
{
	cin>>n;
	int ans=(n-1)*pre2[n]%P;
	for(int i=1;i<=n;i++) ans=(ans-2*f[i]%P*((pre1[n]-pre1[i]+P)%P)%P+P)%P;
	cout<<ans<<"\n";
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
