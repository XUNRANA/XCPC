#include <bits/stdc++.h>
using namespace std;
#define N 6010
int n,t,a[N],l[N],r[N],dp[N][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	l[0]=0;
	r[0]=2*n+1;
	for(int i=1;i<=2*n;i++)
	{
		cin>>a[i];
		if(!l[a[i]]) l[a[i]]=i;
		else r[a[i]]=i;
	}
	
	for(int i=n;i>=0;i--)
	{
		for(int j=l[i];j<=r[i];j++)
		{
			dp[i][j]=dp[i][j-1]+i;
			if(r[a[j]]==j&&l[a[j]]>l[i])
			dp[i][j]=max(dp[i][j],dp[i][l[a[j]]-1]+dp[a[j]][j]);	
		}
	} 
	cout<<dp[0][2*n+1]<<"\n";
}
