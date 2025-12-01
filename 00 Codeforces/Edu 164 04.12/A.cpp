#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	m=(n+m-1)/m;
	//cout<<m<<"\n";
	if(n-m>k) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=0;
	cin>>t;
	while(t--) solve();
}
