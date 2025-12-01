#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int inv(int x)
{
	return ksm(x,P-2);
}
int fx(int x)
{
	return (x+P)%P;
}
void solve()
{
	int n,k,x,k1,k1k,b1,ans1,ans2;
	cin>>n>>x>>k;
	n%=P;
	x%=P;	
	k1=(n-2+P)%P*inv((2*(n-1)+P)%P)%P;
	b1=n*(n+1)%P*inv((4*(n-1)+P)%P)%P;
	k1k=ksm(k1,k);
	ans1=k1k*x%P;
	ans2=b1*((1-k1k+P)%P)%P*inv((1-k1+P)%P)%P;
	cout<<(ans1+ans2)%P<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

