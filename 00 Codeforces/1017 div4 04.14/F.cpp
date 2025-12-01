#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[200010];
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	int c=n*m/k;
	//10 14 4
	int x=0;
	if(n%k&&m%k)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				x++;
				if(x>k) x-=k;
				cout<<x<<" ";
			}
			cout<<"\n";
		}
	}
	else
	{
		if(m%k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==1)
				{
					for(int j=1;j<=m;j++)
					{
						x++;
						if(x>k) x-=k;
						cout<<x<<" ";
						p[j]=x;
					}
					cout<<"\n";
				}
				else
				{
					for(int j=1;j<=m;j++) 
					{
						p[j]=p[j]+1;
						if(p[j]>k) p[j]-=k;
						cout<<p[j]<<" ";
					}
					cout<<"\n";
				}
			}
		}
		else
		{
			vector<vector<int>>ans(n+1,vector<int>(m+1,0));
			for(int j=1;j<=m;j++)
			{
				if(j==1)
				{
					for(int i=1;i<=n;i++)
					{
						x++;
						if(x>k) x-=k;
						ans[i][j]=x;
					}
				}
				else
				{
					for(int i=1;i<=n;i++) 
					{
						ans[i][j]=ans[i][j-1]+1;
						if(ans[i][j]>k) ans[i][j]-=k;
					}
				}
			}
			for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<ans[i][j]<<" ";
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
