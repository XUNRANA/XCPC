#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
vector<int>g[100010];
vector<int>idx[100010];
void init()
{
	for(int i=2;i<=1e5;i++)
	{
		for(int j=i;j<=1e5;j+=i)
		g[j].push_back(i);
	}
}
int fx(int k,int l,int r)
{
	int ans=0; 
	while(l<=r)
	{
		int mi=1e9;
		for(auto j:g[k])
		{
			auto it=lower_bound(idx[j].begin(),idx[j].end(),l);
			if(it!=idx[j].end()&&*it<=r) mi=min(mi,*it);
		}
		if(mi<=r) 
		{
			ans+=(mi-l)*k;
			k/=a[mi];
			l=mi;
		}
		else 
		{
			ans+=(r-l+1)*k;
			break;
		}
	}
	return ans;
}
void solve()
{
	int n,q,k,l,r;
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		idx[a[i]].push_back(i);
	}
	while(q--)
	{
		cin>>k>>l>>r;
		cout<<fx(k,l,r)<<"\n";
	}
	for(int i=1;i<=n;i++) idx[a[i]].clear();
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
