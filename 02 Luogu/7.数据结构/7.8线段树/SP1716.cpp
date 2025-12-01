#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc (p<<1)
#define rc (p<<1|1)
#define N 50010
struct node
{
	int l,r,ls,rs,ms,s;
}tr[4*N]; 
int w[N];

void pushup(int p)
{
	tr[p].s=tr[lc].s+tr[rc].s;//区间字段和
	tr[p].ls=max(tr[lc].ls,tr[lc].s+tr[rc].ls);//左边起最大
	tr[p].rs=max(tr[rc].rs,tr[rc].s+tr[lc].rs);//右边起最大
	tr[p].ms=max(tr[lc].rs+tr[rc].ls,max(tr[lc].ms,tr[rc].ms)); 
}


void build(int p,int l,int r)
{
	tr[p]={l,r,0,0,0,0};
	if(l==r) 
	{
		tr[p]={l,r,w[l],w[l],w[l],w[l]};
		return ;
	}
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}

void update(int p,int x,int y)
{
	if(tr[p].l==x&&tr[p].r==x)
	{
		tr[p]={x,x,y,y,y,y};
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,y);
	else update(rc,x,y);
	pushup(p);
}

node query(int p,int x,int y)
{
	if(x<=tr[p].l&&y>=tr[p].r) return tr[p];
	int m=tr[p].l+tr[p].r>>1;
	
	if(y<=m) return query(lc,x,y);//只在左区间 
	else if(x>m) return query(rc,x,y);//只在右区间 
	
	node n1,n2,n3;
	n2=query(lc,x,y);
	n3=query(rc,x,y);
	n1.s=n2.s+n3.s;
	n1.ls=max(n2.ls,n2.s+n3.ls);
	n1.rs=max(n3.rs,n3.s+n2.rs);
	n1.ms=max(max(n2.ms,n3.ms),n2.rs+n3.ls);
	return n1;
}

void solve()
{
	int n,q,op,x,y;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		cin>>op>>x>>y;
		if(op==0) update(1,x,y);
		else cout<<query(1,x,y).ms<<"\n";
	}
}
signed main()
{
	int T=1;
	//cin>>T;
	while(T--) solve();
}
