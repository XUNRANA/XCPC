#include <bits/stdc++.h>
using namespace std;
#define N 10000005
#define M 1000005
#define int long long
int n,tot,ans,p[M],phi[N],sum[N];
bool flg[N];
void sieve(int n)
{
	phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!flg[i]) p[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot&&i*p[j]<=n;j++)
		{
			flg[i*p[j]]=1;
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			else phi[i*p[j]]=phi[i]*phi[p[j]];
		}
	}
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+phi[i];
}
signed main()
{
	cin>>n;
	sieve(n);
	for(int i=1;i<=tot;i++) ans+=2*sum[n/p[i]]-1;
	cout<<ans<<"\n";	 
}
