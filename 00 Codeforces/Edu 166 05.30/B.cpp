#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],b[200010],ans,mi;
void solve()
{
	ans=1;
	mi=1e18;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n+1;i++) cin>>b[i];
	for(int i=1;i<=n;i++) 
	{
		if(a[i]==b[i]) mi=min(mi,abs(a[i]-b[n+1]));
		else
		{
			ans+=abs(a[i]-b[i]);
			if(b[n+1]>=min(a[i],b[i])&&b[n+1]<=max(a[i],b[i])) mi=0;
			else
			{
				mi=min(mi,abs(a[i]-b[n+1]));
				mi=min(mi,abs(b[i]-b[n+1]));
			}
		}
	}
	ans+=mi;
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
