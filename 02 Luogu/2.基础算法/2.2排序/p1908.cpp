#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500010];
int merge(int *a,int l,int m,int r)
{
	int n1=m-l+1,n2=r-m;
	int b[n1],c[n2];
	for(int i=0;i<n1;i++) b[i]=a[i+l];
	for(int i=0;i<n2;i++) c[i]=a[i+m+1];
	int ans=0;
	int i=0,j=0,k=l;
	while(i<n1&&j<n2)
	{
		if(b[i]<=c[j]) a[k++]=b[i++];
		else 
		{
			a[k++]=c[j++];
			ans+=n1-i;
		}
	}
	while(i<n1) a[k++]=b[i++];
	while(j<n2) a[k++]=c[j++];
	return ans;
}
int mergesort(int *a,int l,int r)
{
	int ans=0;
	if(l<r)
	{
		int m=(l+r)/2;
		ans+=mergesort(a,l,m);
		ans+=mergesort(a,m+1,r);
		ans+=merge(a,l,m,r);
	}
	return ans;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<mergesort(a,1,n);
}
