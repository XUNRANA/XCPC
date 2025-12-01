#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,x,a,b;
	cin>>n>>x>>a>>b;
	cout<<x*b+(n-x)*a<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
