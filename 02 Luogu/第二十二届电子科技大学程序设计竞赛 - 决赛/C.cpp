#include <bits/stdc++.h>
using namespace std;
#define p 998244353
#define int long long
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
void solve()
{
	int n;
	cin>>n;
	cout<<n*(n+1)%p*(2*n+1)%p*ksm(6,p-2)%p<<"\n";
}
signed main()
{
	int t;
	cin>>t;
	while(t--) solve();
}
