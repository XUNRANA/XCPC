#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,l,r,a[1000010],p[1000010],ans;
int get(int x)
{
	int u=x/n;
	int res=u*p[n];
	int v=x%n;
	if(v)
	{
		u=(u-1+n)%n+1;
		if(u+v<=n) res+=p[u+v]-p[u];
		else res+=p[u+v-n]+p[n]-p[u];
	}
	return res;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
	
	while(q--)
	{
		cin>>l>>r;
		cout<<get(r)-get(l-1)<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
