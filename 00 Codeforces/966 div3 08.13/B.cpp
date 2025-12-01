#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],f[200010];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],f[i]=0;
	f[n+1]=0;
	f[a[1]]=1;
	for(int i=2;i<=n;i++)
	{
		if(!f[a[i]-1]&&!f[a[i]+1])
		{
			cout<<"NO\n";
			return ;
		}
		f[a[i]]=1;
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
