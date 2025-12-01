#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,y,a=1e18,b=1e18,c,d;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		a=min(a,x);
		c=max(c,x);
		b=min(b,y);
		d=max(d,y);
	}
	cout<<max(c-a+1,d-b+1)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
