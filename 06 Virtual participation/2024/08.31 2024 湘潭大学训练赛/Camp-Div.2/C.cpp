#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long
int ans,l,r,n,a[N],b[N],p[N];
#define lc p<<1
#define rc p<<1|1
struct node
{
	int l,r,g;
}tr[N<<2];
void pushup(int p)
{
	tr[p].g=__gcd(tr[lc].g,tr[rc].g);
}
void build(int p,int l,int r)
{
	tr[p]={l,r,a[l]};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
int query(int p,int l,int r)
{
	if(r<l) return 0;
	if(l<=tr[p].l&&tr[p].r<=r) return tr[p].g;
	int m=tr[p].l+tr[p].r>>1;
	if(r<=m) return query(lc,l,r);
	if(l>m) return query(rc,l,r);
	return __gcd(query(lc,l,r),query(rc,l,r));
}
bool ck(int i,int x)
{
	return p[x]-p[i-1]>=query(1,i,x);
}
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) p[i]=p[i-1]+b[i];
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(ck(i,mid)) r=mid-1;
			else l=mid+1;
		}
		ans+=n-l+1;
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
