#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,b,sum,ans,p[1001],c[1010],s[1010];
signed main()
{
	cin>>n>>b;
	for(int i=1;i<=n;i++) cin>>p[i]>>c[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==i) s[j]=p[j]/2+c[j];
			else s[j]=p[j]+c[j];
		}
		sort(s+1,s+1+n);
		sum=0;
		for(int j=1;j<=n;j++)
		{
			if(sum+s[j]>b) 
			{
				sum+=s[j];
				ans=max(ans,j-1);
				break;
			}
			sum+=s[j];
		}
		if(sum<=b) ans=n;
	}
	cout<<ans<<"\n";
}

