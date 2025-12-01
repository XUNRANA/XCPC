#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a>b) swap(a,b);
	if(b>c) swap(b,c);
	if(a>b) swap(a,b);
	cout<<c-a+c-b;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
