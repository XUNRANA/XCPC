#include <bits/stdc++.h>
using namespace std;
long long n,k,ans1,ans2,l,r,mid,a[100010];
long long check(long long x)
{
	long long ans=0,s=0;
	for(int i=1;i<=n;i++)
	{
		s=max(s+a[i],0ll);
		if(s>=x) s=0ll,ans++;
	}
	return ans;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	l=1,r=1e18;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)<=k)
		{
			r=mid-1;
			if(check(mid)==k) ans1=mid;
		}
		else l=mid+1;
	}
	
	l=1,r=1e18;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)>=k)
		{
			l=mid+1;
			if(check(mid)==k) ans2=mid;
		}
		else r=mid-1;
	}
	
	if(ans1==0) cout<<-1;
	else cout<<ans1<<" "<<ans2;
} 
