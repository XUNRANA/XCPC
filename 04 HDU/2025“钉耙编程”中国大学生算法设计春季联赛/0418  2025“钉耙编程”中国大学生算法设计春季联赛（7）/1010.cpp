#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int jc[200010];
void init()
{
	jc[0]=1;
	for(int i=1;i<=200000;i++) jc[i]=jc[i-1]*i%P;
}
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
int C(int a,int b)
{
	return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	cout<<C(n,m)<<"\n";
    
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
