#include <bits/stdc++.h>
using namespace std;
long long n,ans,a[310],b[310];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n,j=1;
	while(l<=r)
	{
		b[j++]=a[r--];
		if(l<r) b[j++]=a[l++];
	}
	for(int i=1;i<j;i++) ans+=(b[i]-b[i-1])*(b[i]-b[i-1]);
	cout<<ans;
} 
