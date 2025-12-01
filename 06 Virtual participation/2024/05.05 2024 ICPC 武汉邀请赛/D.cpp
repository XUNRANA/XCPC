#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 5010
int ans,res,n,l,r,a[N],sum[N],f[N][2*N],g[N][2*N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	for(int s=1;s<=n;s++)
	{
		for(int t=1;t<=2*n;t++)
		{
			l=max(1ll,s-t);
			r=min(n,s+t);
			g[s][t]=max(sum[s]-sum[l-1],sum[r]-sum[s-1]);//不折返的最大值 
		}
	}
	//左移折返 
	for(int s=1;s<=n;s++)
	{
		for(int t=1;t<=2*n;t++)
		{
			f[s][t]=max(f[s-1][t-1],g[s][t]);
		}
	}
	
	//右移折返 
	for(int s=n;s>=1;s--)
	{
		for(int t=1;t<=2*n;t++)
		{
			g[s][t]=max(g[s][t],g[s+1][t-1]);//更新g数组 
			f[s][t]=max(f[s][t],g[s][t]);//更新f数组 
		}
	}
	
	
	for(int i=1;i<=n;i++)
	{
		res=0;
		for(int j=1;j<=2*n;j++) res^=j*f[i][j];
		ans^=res+i;
	}
	cout<<ans<<"\n";
}
