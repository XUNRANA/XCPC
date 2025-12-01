#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int jc[1010];
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
void init()
{
	jc[0]=1;
	for(int i=1;i<=1000;i++) jc[i]=jc[i-1]*i%P;
}
int C(int a,int b)
{
	if(b==0) return 1;
	return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}
void solve()
{
	init();
	int n,t;
	cin>>n;
	vector<int>c(4);
	for(int i=1;i<=n;i++) cin>>t,c[t]++;
	
	int ans=0;
	for(int i=0;i<=c[2];i++)
	{
		for(int j=0;j<=c[3];j++)
		{
			ans=(ans+C(c[2],i)*C(c[3],j)%P*(i+1)%P*(j+1)%P)%P;
		}
	}
	ans=(ans*ksm(2,c[1])%P-1+P)%P;
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

