#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,s;
#define P 998244353
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
void solve()
{
	s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		s+=t;
		s%=P;
	}
	cout<<s*ksm(n,P-2)%P<<"\n";
}
signed main()
{
	int T=1;
//	cin>>T;
	while(T--) solve();
}
