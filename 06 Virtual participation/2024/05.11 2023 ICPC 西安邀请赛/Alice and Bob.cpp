#include <bits/stdc++.h>
using namespace std;
#define p 998244353
#define int long long
int n,ans,a[10000010],l,r;
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int C(int a1,int b1)
{
	return a[a1]*ksm(a[b1]*a[a1-b1]%p,p-2)%p;
}
signed main()
{
	cin>>n;
	a[0]=a[1]=1;
	for(int i=2;i<=10000000;i++) a[i]=a[i-1]*i%p;
	for(int i=2;i<=n;i++)
	{
		l=i-1;
		r=n-i;
		if(r>=l) ans+=(a[n-1]-C(r,l)*a[l]%p*a[r]%p+p)%p;
		else ans+=a[n-1];
		ans%=p;
	}
	cout<<(a[n]-ans+p)%p<<"\n";
}
