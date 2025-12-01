#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define N 300010
int n,k,a[N],p[N],s[N],ans;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++) p[i]=__gcd(a[i],p[i-1]);
	s[n+1]=0;
	for(int i=n;i>=1;i--) s[i]=__gcd(a[i],s[i+1]);
	
	ans=p[n];
	
	for(int i=1;i<=n;i++)
	{
		if(p[i-1]>p[i]||i==1)
		{
			int g=0;
			for(int j=i;j<=n;j++)
			{
				g=__gcd(a[j]+k,g);
				ans=max(ans,__gcd(p[i-1],__gcd(g,s[j+1])));
			}
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
