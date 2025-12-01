#include <bits/stdc++.h>
using namespace std;
#define N 300010
#define lc p<<1
#define rc p<<1|1
int a[N];
struct node
{
	int l,r,v,lz;
}tr[N<<2];
void pushup(int p)
{
	tr[p].v=tr[lc].v^tr[rc].v;
}
void build(int p,int l,int r)
{
	tr[p]={l,r,a[l],0};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
void update(int p,int x,int y)
{
	if(tr[p].l==tr[p].r&&tr[p].l==x) 
	{
		tr[p].v^=y;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,y);
	else update(rc,x,y);
	pushup(p);
}
int query(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].v;
	int m=tr[p].l+tr[p].r>>1;
	if(y<=m) return query(lc,x,y);
	if(x>m) return query(rc,x,y);
	return query(lc,x,y)^query(rc,x,y);
}

void solve()
{
	int n,m,op,x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];	
	build(1,1,n);
	while(m--)
	{
		cin>>op>>x>>y;
		if(op==1) update(1,x,y);
		else cout<<query(1,x,y)<<"\n";
	}	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

