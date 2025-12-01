#include <bits/stdc++.h>
using namespace std;
long long t,n,mx,mi,t1;
void solve()
{
	cin>>n;
	mx=0;
	mi=1e9;
	while(n--)
	{
		cin>>t1;
		mx=max(mx,t1);
		mi=min(mi,t1);
	}
	cout<<mx-mi<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--) solve();
}
