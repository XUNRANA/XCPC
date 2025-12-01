#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],p[100010],x,ans;
void solve()
{
	cin>>n;
	x=1;
	for(int i=1;i<=n;i++) cin>>a[i],p[i]=p[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		if(x>=a[i]) x+=a[i];
		else 
		{
			while(x<a[i])
			{
				x+=1+p[i-1];
				ans++;
			}
			x+=a[i];
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
/*
6
2 0 5 9 22 30
*/
