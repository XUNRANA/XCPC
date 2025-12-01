#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define lc p<<1
#define rc p<<1|1
struct node
{
	int l,r;
	int lp;//左边界最长空闲 
	int rp;//右边界最长空闲 
	int vp;//整体最长空闲 
}tr[N<<2]; 
void pushup(int p)
{
	tr[p].lp=tr[lc].lp;
	if(tr[lc].vp==tr[lc].r-tr[lc].l+1) tr[p].lp+=tr[rc].lp;
	
	
	tr[p].rp=tr[rc].rp;
	if(tr[rc].vp==tr[rc].r-tr[rc].l+1) tr[p].rp+=tr[lc].rp;
	
	tr[p].vp=max({tr[p].lp,tr[p].rp,tr[lc].rp+tr[rc].lp,tr[lc].vp,tr[rc].vp});
}
void build(int p,int l,int r)
{
	tr[p]={l,r,1,1,1};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}

void update(int p,int l,int r)
{
	if(tr[p].l==l&&tr[p].r==r)
	{
		tr[p].lp^=1;
		tr[p].rp^=1;
		tr[p].vp^=1;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(l<=m) update(lc,l,r);
	else update(rc,l,r);
	pushup(p);
}

int query(int p,int x)
{
	if(tr[p].vp<x) return -1;//特判无解 
	
	if(tr[p].lp>=x) return tr[p].l;//左区间左边界 
	
	if(tr[lc].vp>=x) return query(lc,x);//左区间某个地方 

	if(tr[lc].rp+tr[rc].lp>=x) return tr[lc].r-tr[lc].rp+1;//左区间+右区间 
	
	return query(rc,x);//只能寻找右区间 
}
void solve()
{
	int n,q,op,x;
	cin>>n>>q;
	build(1,1,n);
	while(q--)
	{
		cin>>op>>x;
		if(op==1) update(1,x,x);
		else
		{
			int res=query(1,x);
			if(res+x-1>n||res==-1) cout<<"-1\n";
			else cout<<res<<" "<<res+x-1<<"\n";
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
