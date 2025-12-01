#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110][5010];
int a1[110][5010];
int s[110][5010];
int s1[110][5010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	}
	
	int mx=-1e9;
	int l=-1;
	int r=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum=s[j][m]-s[i-1][m]-s[j][0]+s[i-1][0];
			if(sum>mx)
			{
				mx=sum;
				l=i;
				r=j;
			}
			else if(sum==mx)
			{
				if(j-i<r-l)
				{
					l=i;
					r=j;
				}
			}
		}
	}
	int mx1=-1e9;
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=m;j++)
		{
			int sum=s[l-1][j]-s[l-1][i-1]-s[0][j]+s[0][i-1];
			sum+=s[n][j]-s[n][i-1]-s[r][j]+s[r][i-1];
			mx1=max(mx1,sum);
		}
	}
	cout<<mx+mx1<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
