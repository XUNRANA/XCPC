#include <bits/stdc++.h>
using namespace std;
int l,r,n,m,mid,cnt,s,a[50010],i,ans;
int main()
{
	cin>>l>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=l;
	for(int i=n+1;i>=1;i--) a[i]-=a[i-1];
	m=n+1-m;
	r=l,l=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		i=1,cnt=0;
		while(i<=n+1)
		{
			s=a[i];
			while(i<=n&&s<mid) s+=a[++i];
			i++;
			cnt++;
		}
		if(cnt>=m) l=mid+1;
		else r=mid-1;
	}
	ans=(l+r)/2;
	
	for(int i=1;i<=(n+1)/2;i++) swap(a[i],a[n+1-i+1]);
	r=l,l=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		i=1,cnt=0;
		while(i<=n+1)
		{
			s=a[i];
			while(i<=n&&s<mid) s+=a[++i];
			i++;
			cnt++;
		}
		if(cnt>=m) l=mid+1;
		else r=mid-1;
	}
	ans=min(ans,(l+r)/2);
	cout<<ans;
}
