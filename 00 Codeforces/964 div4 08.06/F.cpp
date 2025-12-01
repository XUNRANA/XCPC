#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int ans,n,k,t,c[2],jc[200010];
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
	if(b==0) return 1;
	return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}

void solve()
{
	ans=c[0]=c[1]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		if(t&1) c[1]++;
		else c[0]++;
	}
	for(int i=k;i>=k/2+1;i--)
	{
		if(i>c[1]||k-i>c[0]) continue;
		else 
		{
			ans+=C(c[1],i)*C(c[0],k-i)%P;
			ans%=P;	
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	jc[0]=jc[1]=1;
	for(int i=2;i<=200000;i++) jc[i]=jc[i-1]*i%P;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

