#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans;
int get(int l,int r)
{
	if(l>r) return 0;
	return (l+r)*(r-l+1)/2;
}
void solve()
{
	cin>>n>>k;
	if(n==1) cout<<k<<"\n";
	else
	{
		int l=k,r=k+n-1;
		int s=(l+r)*(r-l+1)/2;
		int l1=l,r1=r;
		while(l1<=r1)
		{
			int m1=l1+r1>>1;
			if(2*get(l,m1)>s) r1=m1-1;
			else l1=m1+1;
		}
		int ans=1e18;
		for(int i=max(l,l1-1);i<=min(l1+1,r);i++) ans=min(ans,abs(s-2*get(l,i)));
		cout<<ans<<"\n";
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
