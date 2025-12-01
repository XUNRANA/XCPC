#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,n,w,ans;
int ck(int mid,int x)
{
	return abs(x*a+mid*b+(n-mid-x)*c-w);
}
void solve()
{
	ans=1e18;
	cin>>a>>b>>c>>n>>w;
	for(int i=0;i<=n;i++)
	{
		int l=0,r=n-i,ml,mr;
		while(l<=r)
		{
			ml=l+(r-l)/3;
			mr=r-(r-l)/3;
			ans=min({ans,ck(ml,i),ck(mr,i)});
			if(ck(ml,i)>ck(mr,i)) l=ml+1;
			else r=mr-1;
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
