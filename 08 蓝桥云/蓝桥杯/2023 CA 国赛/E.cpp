#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,l,r,mid,a[100010],b[100010];
bool ck(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int j=upper_bound(b+1,b+1+m,x-a[i])-b;
		cnt+=j-1;
		if(cnt>=k) return true;
	}
	return false;
}
signed main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	l=2,r=2e9;
	while(l<=r)
	{
		mid=l+r>>1;
		if(ck(mid)) r=mid-1;
		else l=mid+1; 
	}
	cout<<l<<'\n';
}
