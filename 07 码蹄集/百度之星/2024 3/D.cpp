#include <bits/stdc++.h> 
using namespace std;
#define lc p<<1
#define rc p<<1|1
#define N 300010
int n,q;
string s;
struct node
{
	int l,r,len,lz,c0,c1;
}tr[N<<2];
void pushup(int p)
{
	if(tr[lc].len&1)
	{
		tr[p].c0=tr[lc].c0+tr[rc].c1;
		tr[p].c1=tr[lc].c1+tr[rc].c0;
	}
	else
	{
		tr[p].c0=tr[lc].c0+tr[rc].c0;
		tr[p].c1=tr[lc].c1+tr[rc].c1;
	}
}
void pushdown(int p)
{
	if(tr[p].lz)
	{
		swap(tr[lc].c0,tr[lc].c1);
		swap(tr[rc].c0,tr[rc].c1);
		tr[lc].lz^=1;
		tr[rc].lz^=1;
		tr[p].lz^=1;
	}
}
void build(int p,int l,int r)
{
	tr[p]={l,r,r-l+1,0,s[l]-'0',(s[l]-'0')^1};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}

void update(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y)
	{
		swap(tr[p].c0,tr[p].c1);
		tr[p].lz^=1;
		return ;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,y);
	if(y>m) update(rc,x,y);
	pushup(p);
}
node query(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p];
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(y<=m) return query(lc,x,y);
	if(x>m)	return query(rc,x,y);
	node n1,n2,n3;
	n2=query(lc,x,y);
	n3=query(rc,x,y);
	if(n2.len&1)
	{
		n1.c0=n2.c0+n3.c1;
		n1.c1=n2.c1+n3.c0;
	}
	else
	{
		n1.c0=n2.c0+n3.c0;
		n1.c1=n2.c1+n3.c1;
	}
	n1.len=n2.len+n3.len;
	n1.l=n2.l;
	n1.r=n3.r;
	return n1;
}
int main( )
{
	int op,x,y;
	cin>>n>>q;
	cin>>s;
	s=" "+s;
	build(1,1,n);
	for(int i=1;i<=4*n;i++) cout<<tr[i].l<<" "<<tr[i].r<<" "<<tr[i].c0<<" "<<tr[i].c1<<"\n";
	while(q--)
	{
		cin>>op>>x>>y;
		if(op==1) update(1,x,y);
		else cout<<min(query(1,x,y).c0,query(1,x,y).c1)<<"\n";
	}
}
