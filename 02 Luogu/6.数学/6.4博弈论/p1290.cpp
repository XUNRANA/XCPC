#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,f;
void solve()
{
	cin>>n>>m;
	if(n>m) swap(n,m);
	f=1;

	while(n&&m)
	{
		if(m%n==0)
		{
			if(f) cout<<"Stan wins\n";
			else cout<<"Ollie wins\n";
			return ;
		}
		if(m/n>=2)
		{
			if(f) cout<<"Stan wins\n";
			else cout<<"Ollie wins\n";
			return ;
		}
		else 
		{
			m-=n;
			swap(n,m);
		}
		f^=1;
	}
	if(f) cout<<"Stan wins\n";
	else cout<<"Ollie wins\n";
		
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
