#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,x[1010],y[1010],ans;
map<array<int,3>,int>mp;
int dis(int x,int y)
{
	return x*x+y*y;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
		ans+=mp[{x[i]+x[j],y[i]+y[j],dis(x[i]-x[j],y[i]-y[j])}];
		mp[{x[i]+x[j],y[i]+y[j],dis(x[i]-x[j],y[i]-y[j])}]++;
	}
	cout<<ans<<"\n";
}

/*
6
1 1
1 2
1 3
2 1
2 2
2 3
*/
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

