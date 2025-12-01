#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],b[200010],s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i],b[i]=a[i];
	sort(a+1,a+1+n);
	map<long long,long long>m;
	s-=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]) m[a[i-1]]=s;
		s-=a[i];
	}
	m[a[n]]=0;
	for(int i=1;i<=n;i++) cout<<m[b[i]]<<" ";
}
