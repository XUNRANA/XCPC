#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010];
int r,w,d[200010];
int b[200010],ans;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],d[i]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>r>>w;
		d[r]+=w;
	}
	int mi=a[1],idx=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<mi)
		{
			mi=a[i];
			idx=i;
		}
		if(d[i]!=0) 
		{
			a[idx]-=d[i];
			mi=a[idx];
		}
	}
	sort(a+1,a+1+n);
	ans=0;
	for(int i=1;i<=n;i++) 
	{
		ans+=a[i];
		cout<<ans<<" ";
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
