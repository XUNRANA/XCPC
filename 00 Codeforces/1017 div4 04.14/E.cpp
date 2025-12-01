#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
//1000
//1101
//0100
//0101
//1111
int c[30];
void solve()
{
	int n;
	cin>>n;
	for(int j=29;j>=0;j--) c[j]=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		for(int j=29;j>=0;j--) c[j]+=(a[i]>>j&1);
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		for(int j=29;j>=0;j--)
		{
			if(a[i]>>j&1) ans+=(n-c[j])*(1ll<<j);
			else ans+=c[j]*(1ll<<j);
		}
		res=max(res,ans);
	}
	cout<<res<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
