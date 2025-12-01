#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[300010],c,c1,ans;
void solve()
{
	c=c1=1;
	ans=1e9;
	cin>>n; 
	for(int i=1;i<=n;i++) cin>>a[i],a[n+i]=a[i];
	if(n==1)
	{
		cout<<0<<"\n";
		return ;
	}
	for(int i=2;i<=2*n;i++)
	{
		if(a[i]>=a[i-1]) c++;
		else c=1;
		
		if(a[i]<=a[i-1]) c1++;
		else c1=1;
		
		if(c==n) 
		{
			if(i==n) ans=min(0ll,ans);
			else ans=min({n-(i-n),i-n+1+1,ans});
		}
		
		if(c1==n)
		{
			if(i==n) ans=min(1ll,ans);
			else ans=min({n-(i-n)+1,1+i-n,ans});
		}
	}
	if(ans==1e9) cout<<"-1\n";
	else cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
