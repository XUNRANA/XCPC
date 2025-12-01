#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,a[100010],sum[100010];
int f[100010][20];
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	int j=1;
	for(int i=1;i<=n;i++)
	{
		if(sum[n]-sum[i-1]<=k) f[i][0]=n+1;
		else
		{
			while(sum[j]-sum[i-1]<=k) j++;
			f[i][0]=j;
		}
	}
	
	for(int i=0;i<=19;i++) f[n+1][i]=n+1;
	
	for(int j=1;j<=19;j++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=i,tp=m;
		for(int j=19;j>=0;j--) if(tp>>j&1) x=f[x][j];
		ans=max(ans,x-i);
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
