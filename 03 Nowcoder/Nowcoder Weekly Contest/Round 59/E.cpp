#include <bits/stdc++.h>
using namespace std;
int n,ans,sum;
int a[2010][2010],p[2010][2010],l[2010][2010],r[2010][2010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]) sum++;
			a[i][j+n]=a[i+n][j]=a[i+n][j+n]=a[i][j];
		}
	}
	
	for(int i=1;i<=2*n;i++)
	{
		for(int j=1;j<=2*n;j++)
		{
			l[i][j]=l[i-1][j-1]+(a[i][j]==1);
			r[i][j]=r[i-1][j+1]+(a[i][j]==1);
		}
	}
	
	ans=1e9;
	for(int i=1;i<=2*n;i++)
	{
		for(int j=1;j<=2*n;j++)
		{
			if(i>=n&&j>=n)
			{
				if(n&1)
				{
					int x1=l[i][j]-l[i-n][j-n];
					int x2=r[i][j-n+1]-r[i-n][j+1];
					int mx=(i+i-n+1)/2;
					int my=(j+j-n+1)/2;
					int res=x1+x2;
					if(a[mx][my]) res--; 
					ans=min(ans,2*n-1-res+sum-res);
				}
				else
				{
					int x1=l[i][j]-l[i-n][j-n];
					int x2=r[i][j-n+1]-r[i-n][j+1];
					int res=x1+x2;
					ans=min(ans,2*n-res+sum-res);
				}
			}
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
