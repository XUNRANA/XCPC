#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,ans,x,a[25],res;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cin>>x;
	ans=0;
	for(int i=(1ll<<(n-1));i<=(1ll<<n)-1;i++)
	{
		res=x;
		for(int j=0;j<=n-1;j++) if(i>>j&1) res%=a[n-j]; 
		ans=max(res,ans);
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=1;
	//cin>>t1;
	while(t1--) solve();
} 
