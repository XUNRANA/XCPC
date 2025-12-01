#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc p<<1
#define rc p<<1|1
#define N 100010
int n,q,m,w[N],op,x,y,k;
struct node
{
	int l,r,sum,ad1,ad2;
}tr[4*N];

void pushup(int p)
{
	tr[p].sum=tr[lc].sum+tr[rc].sum;
	tr[p].sum%=m;
}
void pushdown(int p)
{
	tr[lc].sum=(tr[lc].sum*tr[p].ad2%m+(tr[lc].r-tr[lc].l+1)*tr[p].ad1%m)%m;
	tr[rc].sum=(tr[rc].sum*tr[p].ad2%m+(tr[rc].r-tr[rc].l+1)*tr[p].ad1%m)%m;
	
	tr[lc].ad1=(tr[lc].ad1*tr[p].ad2%m+tr[p].ad1)%m;
	tr[rc].ad1=(tr[rc].ad1*tr[p].ad2%m+tr[p].ad1)%m;
	
	tr[lc].ad2=tr[lc].ad2*tr[p].ad2%m;
	tr[rc].ad2=tr[rc].ad2*tr[p].ad2%m;
	
	tr[p].ad1=0;
	tr[p].ad2=1;
}
void build(int p,int l,int r)
{
	tr[p]={l,r,w[l],0,1};
	if(l==r) return ;
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(p);
}
void add(int p,int x,int y,int k)
{
	if(x<=tr[p].l&&y>=tr[p].r)
	{
		tr[p].sum+=(tr[p].r-tr[p].l+1)*k%m;
		tr[p].sum%=m;
		tr[p].ad1+=k;
		tr[p].ad1%=m;
		return ;
	}
	pushdown(p);
	int mid=tr[p].l+tr[p].r>>1;
	if(x<=mid) add(lc,x,y,k);
	if(y>mid) add(rc,x,y,k);
	pushup(p);
}

void mul(int p,int x,int y,int k)
{
	if(x<=tr[p].l&&y>=tr[p].r)
	{
		tr[p].ad1*=k;
		tr[p].ad1%=m;
		tr[p].sum*=k;
		tr[p].sum%=m;
		tr[p].ad2*=k;
		tr[p].ad2%=m;
		return ;
	}
	pushdown(p);
	int mid=tr[p].l+tr[p].r>>1;
	if(x<=mid) mul(lc,x,y,k);
	if(y>mid) mul(rc,x,y,k);
	pushup(p);
}

int query(int p,int x,int y)
{
	if(x<=tr[p].l&&y>=tr[p].r) return tr[p].sum;
	pushdown(p);
	int mid=tr[p].l+tr[p].r>>1;
	int sum=0;
	if(x<=mid) sum+=query(lc,x,y),sum%=m;
	if(y>mid) sum+=query(rc,x,y),sum%=m;
	return sum%m;
}

signed main()
{
	cin>>n>>q>>m;
	for(int i=1;i<=n;i++) cin>>w[i],w[i]%m;
	build(1,1,n);
	for(int i=1;i<=4*n;i++) cout<<tr[i].l<<" "<<tr[i].r<<" "<<tr[i].sum<<" "<<tr[i].ad1<<" "<<tr[i].ad2<<"\n"; 
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y>>k;
			mul(1,x,y,k%m);
		}
		else if(op==2)
		{
			cin>>x>>y>>k;
			add(1,x,y,k%m);
		}
		else
		{
			cin>>x>>y;
			cout<<query(1,x,y)<<"\n";
		}
		for(int i=1;i<=4*n;i++) cout<<tr[i].l<<" "<<tr[i].r<<" "<<tr[i].sum<<" "<<tr[i].ad1<<" "<<tr[i].ad2<<"\n"; 
	}
	
} 
