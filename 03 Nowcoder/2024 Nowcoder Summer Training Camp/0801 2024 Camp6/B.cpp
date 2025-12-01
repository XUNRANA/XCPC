#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
void solve()
{
	cin>>n>>k;
	k=min(k,n-k);
	if(n%2==0&&n/2==k) ans=n;
	else ans=n*k+1;
	cout<<ans<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
