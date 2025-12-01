#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,s,ans,x;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		s+=t;
	}
	for(int i=31;i>=0;i--)
	{
		x=(1ll<<i);
		if((x-1)*n<s)
		{
			if(x*n<=s) s-=x*n;
			else s%=x;
			ans+=x;
		}
	}
	cout<<ans<<"\n";
}
