#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc p<<1
#define rc p<<1|1
int n,q,op,x,y,l,r,tr[500010],a[500010];

int lowbit(int x)
{
	return x&-x;
}
int query(int i)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}
void add(int i,int x)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}


struct node
{
	int l,r,mx,lz;
}trr[500010<<2];
void pushup(int p)
{
	trr[p].mx=max(trr[lc].mx,trr[rc].mx);
}
void pushdown(int p)
{
	if(trr[p].lz!=0)
	{
		trr[lc].lz+=trr[p].lz;
        trr[rc].lz+=trr[p].lz;
		trr[lc].mx+=trr[p].lz;
		trr[rc].mx+=trr[p].lz;
		trr[p].lz=0;
	}
}
void build(int p,int l,int r)
{
	trr[p]={l,r,query(l-1)-a[l],0};
	if(l==r) return ;
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(p);
}
void update(int p,int l,int r,int k)
{
	if(trr[p].l>=l&&trr[p].r<=r)
	{
		trr[p].mx+=k;
		trr[p].lz+=k;
		return ;
	}
	int mid=trr[p].l+trr[p].r>>1;
	pushdown(p);
	if(l<=mid) update(lc,l,r,k);
	if(r>mid) update(rc,l,r,k);
	pushup(p);
}
int query(int p,int l,int r)
{
	if(trr[p].l>=l&&trr[p].r<=r) return trr[p].mx;
	pushdown(p);
    int mid=trr[p].l+trr[p].r>>1;
    if(r<=mid) return query(lc,l,r);
    if(l>mid) return query(rc,l,r);
	return max(query(lc,l,r),query(rc,l,r));
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i],add(i,a[i]);
	build(1,1,n);
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
            add(x,y-a[x]);//a[x]->y
			update(1,x,x,a[x]-y);//sum(x-1)-a[x]->  sum(x-1)-a[x]  +a[x]-y
			if(x<n) update(1,x+1,n,y-a[x]);// sum(x)-a[x+1]-> sum(x-1)+a[x]+y-a[x]-a[x+1]
			a[x]=y;
		}
		else 
		{
			cin>>l>>r;
			cout<<query(1,l+1,r)-query(l-1)<<"\n";
		}
	}
	for(int i=1;i<=n;i++) add(i,-a[i]);
} 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
    while(T--) solve();
}

/*
#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,q,op,x,y,l,r,tr[500010],a[500010];
int lowbit(int x)
{
	return x&-x;
}
int query(int i)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}
void add(int i,int x)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i],add(i,a[i]);
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			add(x,y-a[x]);
			a[x]=y;
		}
		else
		{
			int ans=-1e9;
			cin>>l>>r;
			for(int i=r;i>=max(l+1,r-30);i--) ans=max(ans,query(i-1)-query(l-1)-a[i]);
			cout<<ans<<"\n";	
		}
	}
	for(int i=1;i<=n;i++) add(i,-a[i]);
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
    while(T--) solve();
}


*/
