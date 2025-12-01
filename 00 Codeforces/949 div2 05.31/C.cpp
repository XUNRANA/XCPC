#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,cnt,a[200010];
void solve()
{
	cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],cnt+=(a[i]==-1);
	if(cnt==n) for(int i=1;i<=n;i++) a[i]=i%2+1;
	else
	{
		for(int i=1,j=-1;i<=n+1;i++)
		{
			if(a[i]!=-1||i==n+1)
			{
				if(j==-1)
				{
					for(int k=i-1;k>=1;k--) a[k]=(a[k+1]==1)? 2:a[k+1]/2;
				}
				else if(i==n+1)
				{
					for(int k=j+1;k<=n;k++) a[k]=(a[k-1]==1)? 2:a[k-1]/2;
				}
				else 
				{
					int l=j,r=i;
					while(l+1<r)
					{
						if(a[l]>a[r]) 
						{
							a[l+1]=a[l]==1? 2:a[l]/2;
							l++;
						}
						else 
						{
							a[r-1]=a[r]==1? 2:a[r]/2;
							r--;
						}
					}
					if(a[l]!=a[r]/2&&a[r]!=a[l]/2)
					{
						cout<<"-1\n";
						return ;
					}
				}
				j=i;
			}
		}
	}
	
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

