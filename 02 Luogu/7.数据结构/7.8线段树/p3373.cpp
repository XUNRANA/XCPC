#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc p<<1
#define rc p<<1|1
#define N 100010
int n,a[N],mod,q;
struct node
{
	int l,r,s,la,lm;
}tr[4*N];
void pushup(int p)
{
	tr[p].s=(tr[lc].s+tr[rc].s)%mod;
}
void pushdown(int p)
{
	if(tr[p].lm!=1)
	{
		tr[lc].s=tr[lc].s*tr[p].lm%mod;
		tr[rc].s=tr[rc].s*tr[p].lm%mod;
		tr[lc].lm=tr[lc].lm*tr[p].lm%mod;
		tr[rc].lm=tr[rc].lm*tr[p].lm%mod;
		tr[p].lm=1;
	}
	if(tr[p].la)
	{
		tr[lc].s=(tr[lc].s+(tr[lc].r-tr[lc].l+1)*tr[p].la%mod)%mod;
		tr[rc].s=(tr[rc].s+(tr[rc].r-tr[rc].l+1)*tr[p].la%mod)%mod;
		tr[lc].la=(tr[lc].la+tr[p].la)%mod;
		tr[rc].la=(tr[rc].la+tr[p].la)%mod;
		tr[p].la=0;
	}
}
void build(int p,int l,int r)
{
	tr[p]={l,r,a[l],0,1};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
void add(int p,int x,int y,int k)
{
	if(x<=tr[p].l&&tr[p].r<=y)//覆盖则修改 
	{
		tr[p].s=(tr[p].s+(tr[p].r-tr[p].l+1)*k%mod)%mod;
		tr[p].la=(tr[p].la+k)%mod;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;//不覆盖裂开 
	pushdown(p);
	if(x<=m) add(lc,x,y,k);
	if(y>m) add(rc,x,y,k);
	pushup(p);	
}
void mul(int p,int x,int y,int k)
{
	if(x<=tr[p].l&&tr[p].r<=y)//覆盖则修改 
	{
		tr[p].s=tr[p].s*k%mod;
		tr[p].lm=tr[p].lm*k%mod;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;//不覆盖裂开 
	pushdown(p);
	if(x<=m) mul(lc,x,y,k);
	if(y>m) mul(rc,x,y,k);
	pushup(p);	
}
int query(int p,int x,int y)//区间求和 
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].s%mod;//全部覆盖，直接返回 
	int m=tr[p].l+tr[p].r>>1;//不是完全覆盖，裂开 
	pushdown(p);
	int sum=0;
	if(x<=m) sum=(sum+query(lc,x,y))%mod;//左子树有部分覆盖 
	if(y>m) sum=(sum+query(rc,x,y))%mod;//右子树有部分覆盖 
	return sum%mod;
}

signed main()
{
	int op,x,y,k;
	cin>>n>>q>>mod;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]%mod;
	build(1,1,n);
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y>>k;
			mul(1,x,y,k);
		}
		else if(op==2)
		{
			cin>>x>>y>>k;
			add(1,x,y,k);
		}
		else
		{
			cin>>x>>y;
			cout<<query(1,x,y)%mod<<"\n";
		}
	}
}
