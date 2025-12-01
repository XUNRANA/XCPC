#include <bits/stdc++.h>
using namespace std;
#define int long long
int p,n,jc[1000010];
void init()
{
	jc[0]=1;
	for(int i=1;i<=p;i++) jc[i]=jc[i-1]*i%p;
}
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
int f(int x)
{
	if(x<p) return jc[x];
	return ksm(jc[p-1],x/p)*jc[x%p]%p*f(x/p)%p;             
}
void solve()
{
	cin>>n;
	cout<<f(n)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T>>p;
	init();
	while(T--) solve();
}
