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
int query(int x,int i)
{
	x++;
	int r=1ll<<(i+1);
	int ans=x/r*(1ll<<i);
	int d=x%r;
	ans+=max(d-(1ll<<i),0ll);
	return ans;
}
int fx(int l1,int r1,int l2,int r2,int i)
{
	int ans=0;
	int s1=r1-l1+1;
	int s2=r2-l2+1;
	ans+=(query(r1,i)-query(l1-1,i))*(s2-(query(r2,i)-query(l2-1,i)))%P;
	ans%=P;
	ans+=(s1-(query(r1,i)-query(l1-1,i)))*(query(r2,i)-query(l2-1,i))%P;
	ans%=P;
	return ans;
}
void solve()
{
	int ans=0;
	int l1,l2,r1,r2;
	cin>>l1>>r1>>l2>>r2;
	for(int i=0;i<32;i++)
	{
		ans+=(1ll<<i)*fx(l1,r1,l2,r2,i)%P;
		ans%=P;
	}
	ans*=inv((r1-l1+1)*(r2-l2+1)%P);
	ans%=P;
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
