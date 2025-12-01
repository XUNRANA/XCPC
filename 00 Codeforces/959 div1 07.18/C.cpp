#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,x,ans,a[N],s[N],f[N];
void solve()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		f[i]=0;
	}
	f[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		int idx=upper_bound(s+1,s+1+n,s[i-1]+x)-s;
		if(idx>n) continue;
		f[i]+=f[idx+1]+1;
	}
	ans=(n+1)*n/2;
	for(int i=1;i<=n;i++) ans-=f[i];
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
