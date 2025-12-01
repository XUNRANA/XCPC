#include <bits/stdc++.h>
using namespace std;
int n,a[70],s,l,r,m;
int check(int x)
{
	if(s%x!=0) return 0;
	for(int l=1,r=n;l<=r;)
	{
		if(a[l]+a[r]==x) l++,r--;
		else if(a[l]+a[r]<x) a[l+1]+=a[l],l++,r--;
		
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
	sort(a+1,a+1+n);
	l=a[n],r=s;
	while(l<=r)
	{
		m=l+r>>1;
		if(check(m)) r=m-1;
		else l=m+1;
	}
	cout<<l;
}
