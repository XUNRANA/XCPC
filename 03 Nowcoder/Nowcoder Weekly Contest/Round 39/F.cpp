#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,l,r,x,y;
char op;
string a,b;
#define lc p<<1
#define rc p<<1|1
struct node
{
	int l,r,c1,c2,c,l1,l2;
}tr[400010];
void pushup(int p)
{
	tr[p].c=tr[lc].c+tr[rc].c;
	tr[p].c1=tr[lc].c1+tr[rc].c1;
	tr[p].c2=tr[lc].c2+tr[rc].c2;
}
void pushdown(int p)
{
	if(tr[p].l1)
	{
		tr[lc].c1=tr[lc].r-tr[lc].l+1;
		tr[lc].c=tr[lc].c2;
		tr[lc].l1=1;
		tr[rc].c1=tr[rc].r-tr[rc].l+1;
		tr[rc].c=tr[rc].c2;
		tr[rc].l1=1;
		tr[p].l1=0;
	}
	if(tr[p].l2)
	{
		tr[lc].c2=tr[lc].r-tr[lc].l+1;
		tr[lc].c=tr[lc].c1;
		tr[lc].l2=1;
		tr[rc].c2=tr[rc].r-tr[rc].l+1;
		tr[rc].c=tr[rc].c1;
		tr[rc].l2=1;
		tr[p].l2=0;
	}
}
void build(int p,int l,int r)
{
	tr[p]={l,r,a[l]=='1',b[l]=='1',a[l]==b[l]&&a[l]=='1'};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
void update(int p,int l,int r,int op)
{
	if(tr[p].l>=l&&tr[p].r<=r)
	{
		if(op==1)
		{
			tr[p].c1=tr[p].r-tr[p].l+1;
			tr[p].c=tr[p].c2;
			tr[p].l1=1;
		}
		else
		{
			tr[p].c2=tr[p].r-tr[p].l+1;
			tr[p].c=tr[p].c1;
			tr[p].l2=1;
		}
		return ;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(l<=m) update(lc,l,r,op);
	if(r>m) update(rc,l,r,op);
	pushup(p);
}

void solve()
{
	cin>>n;
	cin>>a>>b;
	a=" "+a;
	b=" "+b;
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		cin>>op>>x>>y;
		if(op=='A') update(1,x,y,1);
		else update(1,x,y,0);
		cout<<tr[1].c<<"\n";
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
