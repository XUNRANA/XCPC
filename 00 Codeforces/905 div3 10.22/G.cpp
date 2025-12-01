#include<bits/stdc++.h>
using namespace std;
long long T,n,m,a[100005],b[100005],ans,maxn;
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m),ans=0;
		for(long long i=1;i<n;++i) scanf("%lld",&a[i]);
		for(long long i=1;i<=n;++i) scanf("%lld",&b[i]);
		sort(a+1,a+n),sort(b+1,b+n+1);
		long long j=1,flag=0;maxn=0;
		for(long long i=1;i<n;++i)
		{
			while(j<n&&a[i]>=b[j]) maxn=max(maxn,b[j]),++j;
			if(j==n)
			{
				flag=1;
				if(a[i]<b[j]) ans=m*(n-i-1)+max(0ll,m-maxn+1);
				else ans=m*(n-i)+max(0ll,m-max(maxn,b[j])+1);
				break;
			}
			++j;
		}
		if(!flag) ans=max(0ll,m-b[n]+1);
		printf("%lld\n",ans);
	}
	return 0;
}
