#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	int x=0;
	int f=1;
	int i=1;
	while(abs(x)<=n)
	{
		if(f) x-=2*i-1;
		else x+=2*i-1;
		i++;
		f^=1;
	}
	if(f) cout<<"Kosuke\n";
	else cout<<"Sakurako\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
