#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,ans;
void solve()
{
	cin>>b>>a;
	for(int i=1;i<=a;i++)
	{
		int t=(int)(2*a*b-2*b*i+b)/(2*a);
		ans+=t;
		if(2*a*b-2*b*i+b>=2*a*t+a) ans++;
	}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
