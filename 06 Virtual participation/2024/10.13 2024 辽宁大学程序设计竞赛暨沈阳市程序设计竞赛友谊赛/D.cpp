#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
vector<int>g[N];
int n,mi,ans,a[N],b[N],c[N],d[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>d[i];
	mi=1e9;
	for(int i=1;i<=n;i++)
	{
		mi=min(mi,a[i]);
		for(auto j:g[i]) mi=min(j,mi);
		ans+=mi*d[i];
		if(i+c[i]<=n) g[i+c[i]].push_back(b[i]);
	}	
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
