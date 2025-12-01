#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,g,cnt,a[200010];
void solve()
{
	g=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) g=__gcd(a[i],g);
	if(n==1)
	{
		if(a[1]>=k) cout<<k-1<<"\n";
		else cout<<k<<"\n";
	} 
	else if(g==1) cout<<n-1+k<<"\n";
	else
	{
		int sum=(k+g-2)/(g-1);
		sum=min(sum,n);
		cout<<sum+k-1<<"\n"; 
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

