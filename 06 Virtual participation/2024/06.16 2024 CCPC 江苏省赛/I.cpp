#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r,m,ans,a[100010],c[100010];
bool ck(int x)
{
	multiset<int>s[2];
	for(int i=1;i<=n;i++)
	{
		if(s[!c[i]].empty()) s[c[i]].insert(a[i]);
		else
		{
			auto it=s[!c[i]].lower_bound(x-a[i]);
			if(it==s[!c[i]].end()) return false;
			s[c[i]^1].erase(it);
		}
	}
	return true;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	l=1,r=1e9;
	while(l<=r)
	{
		m=l+r>>1;
		if(ck(m)) ans=m,l=m+1;
		else r=m-1;
	}
	cout<<ans<<'\n';
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve(); 
}
