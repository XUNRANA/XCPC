#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define lc p<<1
#define rc p<<1|1
int n,k,a[N];
struct node
{
	int l,r,mx,mi;
}tr[N<<2];
void pushup(int p)
{
	tr[p].l=tr[lc].l;
	tr[p].r=tr[rc].r;
	tr[p].mx=max(tr[lc].mx,tr[rc].mx);
	tr[p].mi=min(tr[lc].mi,tr[rc].mi);
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		tr[p]={l,r,a[l],a[l]};
		return ;
	}
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
int querymx(int p,int l,int r)
{
	if(l<=tr[p].l&&tr[p].r<=r)
	{
		return tr[p].mx;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(r<=m) return querymx(lc,l,r);
	if(l>m) return querymx(rc,l,r);
	return max(querymx(lc,l,r),querymx(rc,l,r));
}

int querymi(int p,int l,int r)
{
	if(l<=tr[p].l&&tr[p].r<=r)
	{
		return tr[p].mi;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(r<=m) return querymi(lc,l,r);
	if(l>m) return querymi(rc,l,r);
	return min(querymi(lc,l,r),querymi(rc,l,r));
}

bool ck(int l,int r)
{
	return querymx(1,l,r)-querymi(1,l,r)>=k;
}
long long ans;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int m=l+r>>1;
			if(ck(i,m)) r=m-1;
			else l=m+1;
		}
		ans+=n-l+1;
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
