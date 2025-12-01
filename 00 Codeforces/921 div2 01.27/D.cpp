#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll t,P=1e9+7,ans,n,m,k,a,b,f,s,p;
ll ksm(ll a,ll b)
{
	ll res=1;
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
	s=ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a>>b>>f,s=(s+f)%P;
	p=2*ksm(n*(n-1)%P,P-2)%P;
	for(int i=1;i<=k;i++)
	{
		ans=(ans+s*p%P)%P;
		s=(s+m*p%P)%P;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--) solve();
}
