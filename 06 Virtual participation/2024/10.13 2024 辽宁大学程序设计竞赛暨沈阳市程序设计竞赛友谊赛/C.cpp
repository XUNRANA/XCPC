#include <bits/stdc++.h>
using namespace std;

int n,p,s,t;
void solve()
{
	cin>>n>>p;
	p/=3;
	while(n--)
	{
		cin>>t;
		s+=t;
	}
	cout<<(s+p-1)/p<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
