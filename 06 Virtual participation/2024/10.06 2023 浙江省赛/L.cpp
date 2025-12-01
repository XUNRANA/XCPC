#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int s=0,ans=0;
	int j=1;
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		while(a[j]*i<=s) j++;
		ans=max(ans,i-j+1);
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
