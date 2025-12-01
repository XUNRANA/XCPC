#include <bits/stdc++.h>
using namespace std;
#define N 120
#define M (1<<10)+200
int n,m,a[N],ans;
int dp[N][M][M];
int lowbit(int x) 
{
	return x&-x;
}
bool ck(int x)
{
	int k=x;
	int c1=lowbit(k),c2;
	k-=c1;
	while(k!=0)
	{
		c2=lowbit(k);
		if((c1<<2)>=c2) return false;
		k-=lowbit(k);
		swap(c1,c2);
	}
	return true;
}
int count(int x)
{
	int k=x,sum=0;
	while(k!=0)
	{
		sum+=(k&1);
		k>>=1;
	}
	return sum;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++)
	{
		char ch;
		cin>>ch;
		if(ch=='H') a[i]+=1<<(j-1);
	}
	

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(1<<m);j++)
		{
			for(int k=0;k<(1<<m);k++)
			{
				if((!ck(j))||(!ck(k))||((j&k)!=0)||((j&a[i])!=0)||((k&a[i-1])!=0)) continue;
				for(int l=0;l<(1<<m);l++)
				{
					if(((l&j)!=0)||((l&k)!=0)||(!ck(k))) continue;
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+count(j));
				}
			}
		}
	}
	for(int i=0;i<(1<<m);i++)
	{
		for(int j=0;j<(1<<m);j++)
		{
			ans=max(ans,dp[n][i][j]);
		}
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
