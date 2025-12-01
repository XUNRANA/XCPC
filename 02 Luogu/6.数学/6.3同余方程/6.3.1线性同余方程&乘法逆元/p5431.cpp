#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,P,k,ans,a[5000010],p[5000010],s[5000010],jc;
int read()//±ÿ–Î”√øÏ∂¡∞° 
{
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*w;
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
void solve()
{
	n=read();
	P=read();
	k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	p[0]=s[n+1]=1;
	for(int i=1;i<=n;i++) p[i]=p[i-1]*a[i]%P;
	for(int i=n;i>=1;i--) s[i]=s[i+1]*a[i]%P;
	jc=1;
	for(int i=1;i<=n;i++) 
	{
		jc=jc*k%P;
		ans=(ans+s[i+1]*p[i-1]%P*jc%P)%P;
	}
	cout<<ans*ksm(p[n],P-2)%P<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
