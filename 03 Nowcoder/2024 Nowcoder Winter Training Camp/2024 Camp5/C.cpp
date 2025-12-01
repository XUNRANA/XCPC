#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]!=1)
	{
		ans+=a[1]-1;
		a[1]=1;
	}
	if(a[n]!=1)
	{
		ans+=a[n]-1;
		a[n]=1;
	}
	for(int i=2;i<=n-2;i++)
	{
		int t=min(a[i],a[i+1]);
		if(t==1) continue;
		ans+=t-1;
		a[i]-=t-1;
		a[i+1]-=t-1;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
