#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 5010
int ans,res,n,l,r,a[N],sum[N],f[N][2*N];
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
			f[s][t]=max(sum[s]-sum[l-1],sum[r]-sum[s-1]);//不折返的最大值 
		}
	}
	
	for(int j=1;j<=2*n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i+1<=n) f[i][j]=max(f[i][j],f[i+1][j-1]);
			if(i-1>=1) f[i][j]=max(f[i][j],f[i-1][j-1]);
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
