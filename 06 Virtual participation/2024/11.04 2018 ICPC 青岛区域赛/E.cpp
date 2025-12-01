#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,a[100010],c[100010],d[100010];
bool ck(int x,int m)
{
	if(!x) return 1;
	for(int i=1;i<=n;i++)
	{
		c[i]=(x+d[i]-1)/d[i];//需要多少次 
		a[i]=0;//目前为止浇了多少次 
	}
	
	for(int i=1;i<=n;i++)
	{
		if(i==n&&a[i]>=c[i]) return 1;
		
		if(m<=0) return 0;
		
		a[i]++;
		m--;
		
		if(a[i]>=c[i]) continue;
		
		int cnt=c[i]-a[i];
		if(2*cnt>m) return 0;
		m-=2*cnt;
		a[i+1]+=cnt;
	}
	return 1; 
}
void solve()
{
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>d[i]; 
	int l=0,r=1e18;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(ck(mid,m)) l=mid+1;
		else r=mid-1;
	}
	cout<<l-1<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
