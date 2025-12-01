#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000010];
int a1[1000010];
int d[1000010];
bool ck(int x)
{
	int l=1;
	for(int i=2;i<=m;i++)
	{
		int r=min(a1[i]-1,l+x-1);
		if(r<a1[i-1]) return 0;
		l=r+1;
	}
	l+=x-1;
	if(l<n) return 0;
	return 1;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	if(m==1)
	{
		cout<<n<<"\n";
		return ;
	}
	if(m==2)
	{
		cout<<(n+1)/2<<"\n";
		return ;
	}
	a[m+1]=a[1]+n;
	for(int i=1;i<=m;i++) d[i]=a[i+1]-a[i]-1;
	int mxi=1;
	for(int i=2;i<=m;i++) if(d[i]>d[mxi]) mxi=i;
	int t=a[mxi]-1;
	for(int i=1;i<=m;i++,mxi++)
	{
		if(mxi==m+1) mxi=1;
		if(a[mxi]-t<=0) a1[i]=a[mxi]-t+n;
		else a1[i]=a[mxi]-t;
	}
	int l=1,r=n;
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
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
