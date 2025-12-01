#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[200010],ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];

	if(n==3&&a[2]&1==1) 
	{
		cout<<"-1\n";
		return ;
	}
	
	int f=1;
	for(int i=2;i<=n-1;i++) 
	if(a[i]>=2) f=0;
	if(f)
	{
		cout<<"-1\n";
		return ;
	}
	
	//2 3 3 3 3 
	for(int i=2;i<=n-1;i++) ans+=a[i]/2+a[i]%2;
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
