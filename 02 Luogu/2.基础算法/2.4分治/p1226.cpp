#include <bits/stdc++.h>
using namespace std;
long long a,b,p;
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		b>>=1;
		a=a*a%p;
	}
	return res;
}
int main()
{
	cin>>a>>b>>p;
	printf("%lld^%lld mod %lld=%lld",a,b,p,ksm(a,b));
} 
