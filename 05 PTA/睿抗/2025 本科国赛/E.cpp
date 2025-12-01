#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int dp[310][310];
int a[310][310];
int sp[310];
int sc[310];
int t[310];
int p[310];
int c[310];
void solve()
{
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>t[i]>>p[i]>>c[i];
		sp[i]=sp[i-1]+p[i];
		sc[i]=sc[i-1]+c[i];
	}
	
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j]=a[i][j]=1e9;
	
	
	
	dp[0][0]=0;
	a[0][0]=0;
	for(int i=1;i<=n;i++) 
	{
		dp[i][0]=dp[i-1][0]+t[i]*p[i];
		a[i][0]=0;
	}
	
	

	
	for(int i=2;i<=n;i++)
	{
		
		for(int k=0;k<i;k++) 
		{
			if(dp[i][k]>=dp[i-1][k]+t[i]*p[i])
			{
				dp[i][k]=dp[i-1][k]+t[i]*p[i];
				a[i][k]=min(a[i][k],a[i-1][k]);
			}
		}
		
		
		for(int j=1;j<=i;j++)
		{
			for(int k=0;k<j;k++)
			{
				if(dp[j][k]+t[j]*(sp[i]-sp[j])<dp[i][k+i-j])
				{
					dp[i][k+i-j]=dp[j][k]+t[j]*(sp[i]-sp[j]);
					a[i][k+i-j]=a[j][k]+sc[i]-sc[j];
				}
				else if(dp[j][k]+t[j]*(sp[i]-sp[j])==dp[i][k+i-j])
				{
					a[i][k+i-j]=min(a[i][k+i-j],a[j][k]+sc[i]-sc[j]);
				}
			}
		}
	}
	

	int mx=dp[n][0];
	for(int i=0;i<=m;i++)
	{
		mx=min(mx,dp[n][i]);
	}

	int mx2=1e9;
	for(int i=0;i<=m;i++)
	{
		if(mx==dp[n][i])
		{
			mx2=min(mx2,a[n][i]);
		}
	}
	
	cout<<mx<<" "<<mx2<<"\n";
}
/*
7 4
1 1 1
2 1 1
3 1 1
5 1 1
8 1 1
10 1 1
1 1 1


7 0
10 1 1
8 1 1
5 1 1
3 1 1
2 1 1
1 1 1
1 1 1

*/
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
