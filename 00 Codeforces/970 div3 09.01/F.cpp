#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
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
int n,a[200010],s,ans;
void solve()
{
	ans=s=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s=(s+a[i])%P;
	for(int i=1;i<=n;i++) 
	{
		s=(s-a[i]+P)%P;
		ans=(ans+s*a[i])%P;
	}
	cout<<2*ans%P*inv(n*(n-1)%P)%P<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

