#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,w,l,r;
struct node
{
	int w,l,r;
}a[100010];
int cnt[100010];
int sum[100010];
bool cmp(node a1,node a2)
{
	return a1.w>a2.w;
}
void solve()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i].w>>a[i].l>>a[i].r;
	
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=n;i++) cnt[i]=cnt[i-1]+a[i].r-a[i].l;
	
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(a[i].r-a[i].l)*a[i].w;
	
	
	int res=0;
	for(int i=1;i<=n;i++) m-=a[i].l,res+=a[i].l*a[i].w;
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int ans1=res-a[i].l*a[i].w;
		
		int m1=m+a[i].l;
		
		int t=cnt[i];
		
		cnt[i]=1e18;
		
		int j=upper_bound(cnt+1,cnt+1+i,m1)-cnt;
		
		cnt[i]=t;
		
		ans1+=sum[j-1]+a[j].w*(m1-cnt[j-1]);
		
		ans=max(ans,ans1);
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
