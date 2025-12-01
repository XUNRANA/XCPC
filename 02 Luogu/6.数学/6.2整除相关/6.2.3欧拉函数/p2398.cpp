#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,f[100010];
signed main()
{
	cin>>n;
	for(int i=n;i;i--)
	{
		f[i]=n/i*(n/i);
		for(int j=i<<1;j<=n;j+=i) f[i]-=f[j];
		ans+=f[i]*i;
	}
	cout<<ans<<"\n";
}
