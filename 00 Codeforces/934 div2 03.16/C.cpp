#include <bits/stdc++.h>
using namespace std;
int n,a[200010],t1,l,r,m,ans;
int ck(int x)
{
	int c=0;
	for(int i=0;i<x;i++) 
	if(a[i]==0) return 0;
	else if(a[i]==1) c++;
	if(c>=2) return 0;
	else return 1;
}
void solve()
{
	ans=0;
	cin>>n;
	for(int i=0;i<n;i++) a[i]=0;
	for(int i=1;i<=n;i++) cin>>t1,a[t1]++;
	l=0,r=n;
	while(l<=r)
	{
		m=l+r>>1;
		if(ck(m)) l=m+1,ans=max(ans,m);
		else r=m-1;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
