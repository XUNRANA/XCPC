#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[1010],s,ans=-1e9;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		ans=max(ans,s);
		if(s<0) s=0;
	}
	if(k==0) cout<<ans<<"\n";
	else
	{
		for(int i=2;i<=n;i++)
		{
			swap(a[i],a[i-1]);
			s=0;
			for(int j=1;j<=n;j++)
			{
				s+=a[j];
				ans=max(ans,s);
				if(s<0) s=0;
			}
			
			swap(a[i],a[i-1]);
		}
		cout<<ans<<"\n";
	}
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
