#include <bits/stdc++.h>
using namespace std;
long long t,n,k,ans;
void solve()
{
	cin>>n>>k;
	if(k<=2*n) ans=(k+1)/2;
	else if(k==4*n-2) ans=2*n;
	else ans=n+(k-2*n+1)/2;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--) solve();
}
