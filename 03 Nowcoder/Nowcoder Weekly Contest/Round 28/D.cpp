#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,s,ans,a[100010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,j=1;j<=n;j++)
	{
		s+=a[j];
		while(s>=k)
		{
			s-=a[i];
			i++;
			//cout<<i<<" "<<j<<"\n";
			ans+=n-j+1;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

