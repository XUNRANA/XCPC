#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mx,cnt,v[100010],w[100010];
void solve()
{
	mx=cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++) if((m|w[i])==m) cnt+=v[i];
	mx=max(mx,cnt);
	for(int i=1;i<=31;i++)
	{
		if(m>>i&1)
		{
			int t=m-(1ll<<i);
			t|=(1ll<<i)-1;
			cnt=0;
			for(int i=1;i<=n;i++) if((t|w[i])==t) cnt+=v[i];
			mx=max(mx,cnt);
		}
	}
	cout<<mx<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
