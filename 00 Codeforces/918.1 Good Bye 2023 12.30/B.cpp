#include <bits/stdc++.h>
using namespace std;
long long t,a,b;
long long gcd(long long a,long long b)
{
	return b==0? a:gcd(b,a%b);
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a==1) cout<<b*b<<"\n";
		else if(b%a==0) cout<<b*b/a<<"\n";
		else cout<<a*b/gcd(a,b)<<"\n";
	}
}
