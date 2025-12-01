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
int n,ans,res,pos,a[200010],pre[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]+a[i];
	pos=1;
	for(int i=2;i<=n;i++) if(pre[i]<pre[pos]) pos=i;
	if(pre[pos]>=0)
	{
		cout<<ksm(2,n)<<"\n";
		return ;
	}
	ans=0,res=1;
	for(int i=1;i<=n;i++)
	{
		if(pre[i]>=0) res*=2;
		res%=P;
		if(pre[i]==pre[pos]) ans+=res*ksm(2,n-i)%P;
		ans%=P;
	}
	cout<<ans<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
