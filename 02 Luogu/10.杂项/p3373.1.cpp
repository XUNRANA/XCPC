#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc p<<1
#define rc p<<1|1
#define N 100010
int n,q,m,op,x,y,k,w[N];
struct node
{
	int l,r,sum,ad,mu;
}tr[4*N];

void pushup(int p)
{
	tr[p].sum=tr[lc].sum+tr[rc].sum;
	tr[p].sum%=m;
}

void pushdown(int p)
{
	tr[lc].sum=(tr[lc].sum*tr[p].mu%m+(tr[lc].r-tr[lc].l+1)*tr[p].ad%m)%m;
	tr[rc].sum=(tr[rc].sum*tr[p].mu%m+(tr[rc].r-tr[rc].l+1)*tr[p].ad%m)%m;
	
	tr[lc].ad=(tr[lc].ad*tr[p].mu%m+tr[p].ad)%m;
	tr[rc].ad=(tr[rc].ad*tr[p].mu%m+tr[p].ad)%m;
	
	tr[lc].mu=tr[p].mu*tr[lc].mu%m;
	tr[rc].mu=tr[p].mu*tr[rc].mu%m;
	
	tr[p].ad=0;
	tr[p].mu=1;
}

void build(int p,int l,int r)
{
	tr[p]={l,r,w[l],0,1};
	if(l==r) return ;//р╤вс╫з╣Ц
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(p); 
}

void add(int p,int x,int y,int k)
{
	if(x<=tr[p].l&&y>=tr[p].r)
	{
		tr[p].ad+=k;
		tr[p].ad%=m;
		tr[p].sum+=(tr[p].r-tr[p].l+1)*k%m;
		tr[p].sum%=m;
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
		tr[p].sum*=k;
		tr[p].sum%=m;
		
		tr[p].mu*=k;
		tr[p].mu%=m;
		
		tr[p].ad*=k;
		tr[p].ad%=m;
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
	int sum=0;
	int mid=tr[p].l+tr[p].r>>1;
	if(x<=mid) sum+=query(lc,x,y),sum%=m;
	if(y>mid) sum+=query(rc,x,y),sum%=m;
	return sum;
}

signed main()
{
	cin>>n>>q>>m;
	for(int i=1;i<=n;i++) cin>>w[i],w[i]%=m;
	build(1,1,n);

	for(int i=1;i<=q;i++)
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
		
	}
}
