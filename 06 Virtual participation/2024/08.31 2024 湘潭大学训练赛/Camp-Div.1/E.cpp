#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int jc[1000010],n,m;
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
int inv(int x)
{
	return ksm(x,P-2);
}
void init()
{
	jc[0]=1;
	for(int i=1;i<=1000000;i++) jc[i]=jc[i-1]*i%P;
}
int C(int a,int b)
{
	return jc[a]*inv(jc[b]*jc[a-b]%P)%P;
}
void solve()
{
	cin>>n>>m;
	if(m>n) cout<<"0\n";
	else cout<<C(n-1,m-1)*inv(ksm(2,n))%P<<"\n";
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

