#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,l,r,m,a[200010];
int ck(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x)
		{
			cnt+=x-a[i];
			if(cnt>k) return 0;
		}
	}
	return 1;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	l=0,r=1e10;
	while(l<=r)
	{
		m=l+r>>1;
		if(ck(m)) l=m+1;
		else r=m-1;
	}
	cout<<l-1<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
