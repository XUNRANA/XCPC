#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,x,y,ans;
int a[300010];
#define P 1000000007
int jc[300010],inv[300010];
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

void init(int n)
{
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%P;
	inv[n]=ksm(jc[n],P-2);
	for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%P;
}
int C(int n,int m)
{
	return jc[n]*inv[m]%P*inv[n-m]%P;
}

void solve()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		n-=2;
		if(x==y) n++;
	}
	ans=k=1;
	for(int i=2;i<=n;i+=2)
	{
		k=2*(i-1)*k%P;
		ans=(ans+k*C(n,i)%P)%P;
	}
	cout<<ans<<"\n";
}

signed main()
{
	init(300010);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
