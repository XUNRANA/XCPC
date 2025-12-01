#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x1,y1,x2,y2,x[100010],y[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	cin>>x1>>y1>>x2>>y2;
	int d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	for(int i=1;i<=n;i++)
	{
		if((x[i]-x2)*(x[i]-x2)+(y[i]-y2)*(y[i]-y2)<=d)
		{
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

