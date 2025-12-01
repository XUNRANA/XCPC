#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,L,R,a[200010];
bool ck1(int x)//max(min) 
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(x>a[i])
		{
			if(sum<x-a[i]) return false;
			else sum-=x-a[i];
		}
		else sum+=a[i]-x;
	}
	return true;	
}

bool ck2(int x)//min(max)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x) sum+=a[i]-x;
		else sum-=min(x-a[i],sum); 
	}
	return sum==0;
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1,r=1e12;
	while(l<=r)
	{
		
		int m=l+r>>1;
		if(ck1(m)) l=m+1;
		else r=m-1;

	}
	L=l-1;
	l=1,r=1e12;
	while(l<=r)
	{
		int m=l+r>>1;
		if(ck2(m)) r=m-1;
		else l=m+1;
	}
	R=l;
	cout<<R-L<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
