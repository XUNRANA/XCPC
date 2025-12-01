#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc (p<<1)
#define rc (p<<1|1)
#define N 100010
struct node
{
	int l,r,ls,rs,ms;
}tr[4*N]; 

void pushup(int p)
{
	tr[p].ls=tr[lc].ls;
	if(tr[lc].ls==tr[lc].r-tr[lc].l+1) tr[p].ls+=tr[rc].ls;
	tr[p].rs=tr[rc].rs;
	if(tr[rc].rs==tr[rc].r-tr[rc].l+1) tr[p].rs+=tr[lc].rs;
	
	tr[p].ms=max({tr[lc].ms,tr[rc].ms,tr[p].ls,tr[p].rs,tr[lc].rs+tr[rc].ls}); 
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

void update(int p,int x,int y)
{
	if(tr[p].l==x&&tr[p].r==x)
	{
		tr[p].ls^=y;
		tr[p].rs^=y;
		tr[p].ms^=y;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,y);
	else update(rc,x,y);
	pushup(p);
}

node query(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p];

	int m=tr[p].l+tr[p].r>>1;

	if(y<=m) return query(lc,x,y);

	if(x>m) return query(rc,x,y);
	
	node n1=query(lc,x,y);
	node n2=query(rc,x,y);
	node n3={n1.l,n2.r,n1.ls,n2.rs,0};
	if(n1.ls==n1.r-n1.l+1) n3.ls+=n2.ls;
	if(n2.rs==n2.r-n2.l+1) n3.rs+=n1.rs;
	n3.ms=max({n1.ms,n2.ms,n3.ls,n3.rs,n1.rs+n2.ls}); 
	return n3;

}
void solve()
{
	int n,q,op,x,y;
	cin>>n>>q;
	build(1,1,n);
	while(q--)
	{
		cin>>op;
		if(op==1) 
		{
			cin>>x;
			update(1,x,1);
		}
		else 
		{
			cin>>x>>y;
			cout<<query(1,x,y).ms<<"\n";
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
