#include <bits/stdc++.h>
using namespace std;
long long k,x,a,p,n;
void solve()
{
	cin>>k>>x>>a;
	p=1;
	for(int i=1;i<=x;i++)
	{
		n=p/(k-1)+1;
		p+=n;
		if(p>a)
		{
			cout<<"NO\n";
			return ;
		}
	}
	if(n*k>p) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
