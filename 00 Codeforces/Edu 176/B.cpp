#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5010];
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==1)
	{
		int ans=0;
		for(int i=2;i<=n;i++) ans=max(a[1]+a[i],ans);
		for(int i=1;i<n;i++) ans=max(a[n]+a[i],ans);
		cout<<ans<<"\n";
	}
	else
	{
		int ans=0;
		sort(a+1,a+1+n);
		for(int i=n;i>=n-k;i--) ans+=a[i];
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

