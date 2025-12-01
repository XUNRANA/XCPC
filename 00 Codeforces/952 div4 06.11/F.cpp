#include <bits/stdc++.h>
using namespace std;
#define int long long
int s,h,n,a[200010],c[200010];
int ck(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(x+c[i]-1)/c[i]*a[i];
		if(sum>=h) return 1;
	}
	return 0;
}
void solve()
{
	cin>>h>>n;
	s=0;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	
	if(s>=h) 
	{
		cout<<1<<"\n";
		return ;
	}
	int l=1,r=1e11;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(ck(mid)) r=mid-1;
		else l=mid+1;
	}
	
	cout<<l<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
