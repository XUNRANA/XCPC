#include <bits/stdc++.h>
using namespace std;
int n,a[300010],b[300010],c[300010];
bool ck(int x)
{
	int s=0,mx=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x) cnt++;
		s+=(b[i]>=x)-(a[i]>=x);
		mx=max(mx,s);
		if(s<0) s=0;
	}
	return 2*(cnt+mx)>n;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	int l=1,r=1e9;
	while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m)) l=m+1;
		else r=m-1;
	}
	cout<<l-1<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
