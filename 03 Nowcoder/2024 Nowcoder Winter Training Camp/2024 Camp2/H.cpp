#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc (p<<1)
#define rc (p<<1|1)
#define N 500010
#define INF 0x3f3f3f3f3f3f3f3fll
struct node
{
	int l,r;
	int sum;//区间和 
	int lmin;//含左端点的最小字段和 
	int rmax;//含右端点的最大字段和 
	int lans;//含左端点的最大答案 
	int rans;//含右端点的最大答案 
	int segans;//含整段的最大答案 
	int ans;//区间答案（可不含整段） 
}tr[4*N]; 
int a[N];
node merge(node l,node r)
{
	node res;
	res.l=l.l;
	res.r=r.r;
	res.sum=l.sum+r.sum;//区间和 
	res.rmax=max(r.rmax,l.rmax+r.sum);//含右端点的最大字段和 
	res.lmin=min(l.lmin,l.sum+r.lmin);//含左端点的最小字段和 
	res.lans=max({l.lans,l.sum+r.lans,l.sum-r.lmin,l.segans-r.lmin});//含左端点的最大答案 
	res.rans=max({r.rans,l.rans-r.sum,l.rmax-r.sum,l.rmax+r.segans});//含右端点的最大答案 
	res.segans=max({l.segans-r.sum,l.sum+r.segans,l.sum-r.sum});
	res.ans=max({l.ans,r.ans,l.rmax-r.lmin,l.rans-r.lmin,l.rmax+r.lans});
	return res; 
}
void build(int p,int l,int r)
{
	if(l==r) 
	{
		tr[p]={l,r,a[l],a[l],a[l],-INF,-INF,-INF,-INF};
		return ;
	}
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	tr[p]=merge(tr[lc],tr[rc]);
}
void update(int p,int x,int y)
{
	if(tr[p].l==x&&tr[p].r==x)
	{
		tr[p]={x,x,y,y,y,-INF,-INF,-INF,-INF};
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,y);
	else update(rc,x,y);
	tr[p]=merge(tr[lc],tr[rc]);
}
node query(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p];
	int mid=tr[p].l+tr[p].r>>1;
	if(y<=mid) return query(lc,x,y);//只在左区间 
	else if(x>mid) return query(rc,x,y);//只在右区间 
	return merge(query(lc,x,y),query(rc,x,y));
}
void solve()
{
	int n,q,op,x,y;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(q--)
	{
		cin>>op>>x>>y;
		if(op==1) update(1,x,y);
		else cout<<query(1,x,y).ans<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
