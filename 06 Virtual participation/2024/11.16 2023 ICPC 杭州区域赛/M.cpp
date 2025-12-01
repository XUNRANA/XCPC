#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[300010],s[300010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	
	int id;
	for(int i=2;i<n;i++) 
	if(a[i]<a[i-1]&&a[i]<a[i+1])
	{
		id=i;
		break;
	}
	
	double ans=0;
	ans=max({1.0*s[id+1]/(id+1),1.0*s[n]/n,1.0*(s[n]-s[id-2])/(n-id+1+1)});
	cout<<fixed<<setprecision(20)<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
