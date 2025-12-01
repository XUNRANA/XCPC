#include <bits/stdc++.h>
using namespace std;
int is(int n)
{
	if(n<2) return 0;
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
int gcd(int a,int b)
{
	return b==0? a:gcd(b,a%b);
}
int main()
{
	int n,k,t;
	cin>>n>>k;
	vector<int>a(n);
	long long sum=0,ans=0;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		sum+=gcd(a[i],k);
		a[i]=gcd(a[i],k);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==1) ans+=sum;
		else 
		{
			long long s=0;
			for(int j=0;j<n;j++) s+=gcd(a[i]*a[j],k);
			ans+=s/a[i];
		}
	}
	cout<<ans;
}