#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[(1ll<<20)],a[1000010],n,ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],c[a[i]]++;
	for(int i=0;i<20;i++)
	{
		for(int j=1;j<(1<<20);j++)
		if(j&(1<<i)) c[j]+=c[j-(1<<i)];
	}
	for(int i=1;i<=n;i++) ans+=c[(1<<20)-1-a[i]];
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
