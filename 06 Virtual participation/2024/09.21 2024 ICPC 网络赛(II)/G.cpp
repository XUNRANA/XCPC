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

int x,y,a0,a1,b,p0,p1,ans,cur;

void solve()
{
	cin>>x>>y>>a0>>a1>>b;
	p0=a0*inv(a0+a1)%P;
	p1=a1*inv(a0+a1)%P;
	
	cur=1;
	ans=0;
	
	while(x&&y)
	{
		if(x>=y)
		{
			ans=(ans+cur*(1-ksm(p1,x/y)+P)%P)%P;
			cur=cur*ksm(p1,x/y)%P;
			x%=y;
		}
		else
		{
			cur=cur*ksm(p0,y/x)%P;
			y%=x;
		}
	}
	
	if(x) ans=(ans+cur)%P;
	
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
