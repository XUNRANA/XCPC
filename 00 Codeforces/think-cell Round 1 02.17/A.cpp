#include <bits/stdc++.h>
using namespace std;
long long a[110],ans,n;
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=2*n;i++) cin>>a[i];
	sort(a+1,a+1+2*n);
	for(int i=1;i<=2*n;i+=2) ans+=a[i];
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
