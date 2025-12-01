#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],ans; 
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++) ans+=2*min(2*a[i],4*a[1])*(n-i);
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
