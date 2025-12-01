#include <bits/stdc++.h>
using namespace std;
#define lc p<<1
#define rc p<<1|1
#define N 500010
#define int long long
struct node
{
	int l,r,mx,mi;
}tr[N<<2];
int a[N];
void pushup(int p)
{
	tr[p].mx=max(tr[lc].mx,tr[rc].mx);
	tr[p].mi=min(tr[lc].mi,tr[rc].mi);
} 
void build(int p,int l,int r)
{
	tr[p]={l,r,0,0};
	if(l==r) 
	{
		tr[p].mx=tr[p].mi=a[l];
		return ;
	}
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
node query(int p,int x,int y)
{
	if(tr[p].l>=x&&tr[p].r<=y) return tr[p];
	int m=tr[p].l+tr[p].r>>1;
	if(y<=m) return query(lc,x,y);
	else if(x>m) return query(rc,x,y);
	node t1,t2,t3;
	t1=query(lc,x,y);
	t2=query(rc,x,y);
	t3.mi=min(t1.mi,t2.mi);
	t3.mx=max(t1.mx,t2.mx);
	return t3;
}
signed main()
{
	int n,q,x,y;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	//cout<<"\n";
	build(1,0,n);
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		cout<<query(1,x-1,y).mx-query(1,x-1,y).mi<<"\n";
	}
}
