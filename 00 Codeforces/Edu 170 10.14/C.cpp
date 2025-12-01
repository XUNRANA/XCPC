#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+1+n);
	int p=a[1],c=1,ans=0;
	//2 2 3 3 3 4 4 4 5 5
	for(int i=1,j=1;i<=n;i++)
	{
		if(a[i]==p) 
		{
			ans=max(ans,i-j+1);
			continue;
		}
		else
		{
			if(a[i]!=p+1)
			{
				ans=max(ans,i-j);
				p=a[i];
				c=1;
				j=i;
			}
			else
			{
				p++;
				c++;
				while(c>k)
				{
					ans=max(ans,i-j);
					j++;
					if(a[j]!=a[j-1]) c--;
				}
				ans=max(ans,i-j+1);
			}
		}
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
