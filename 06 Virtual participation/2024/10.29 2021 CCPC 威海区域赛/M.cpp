#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,m,k;
int jc[100010];
void init()
{
	jc[0]=1;
	for(int i=1;i<=100000;i++) jc[i]=jc[i-1]*i%P;
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
	if(a<b) return 0;
	return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}
int cal(int k)
{
	int ans=0;
	for(int i=1;i*k<=m;i++)
	{
		if(i&1) ans=(ans+C(n-m+1,i)*C(n-i*k,n-m)%P)%P;
		else ans=(ans-C(n-m+1,i)*C(n-i*k,n-m)%P+P)%P;
	}
	return ans;
}
void solve()
{
	cin>>n>>m>>k;
	int ans=0;
	if(k==0)
	{
		if(!m) cout<<"1\n";
		else cout<<"0\n";
	}
	else cout<<(cal(k)-cal(k+1)+P)%P;
}


signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
