#include <bits/stdc++.h>
using namespace std;
long long w,n,i,t,a[30010],b[30010],c[30010];
int main()
{
	cin>>w>>n;
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(b+1,b+1+n);
	for(int j=n;j>=1;j--)
	{
		t=b[j];
		i=1;
		while(c[i]==2||a[i]+t>w) i++;
		a[i]+=t;
		c[i]++;
	}
	for(int i=1;i<=n;i++)
	if(a[i]==0)
	{
		cout<<i-1;
		return 0;
	}
}
