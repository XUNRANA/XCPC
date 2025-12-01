#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n,q,ans,l[N],r[N],x[N],a[N];


#define lc p<<1
#define rc p<<1|1
struct node
{
	int l,r,mx,add;
}tr[N*4];
void pushup(int p)//向上更新 
{
	tr[p].mx=max(tr[lc].mx,tr[rc].mx);
}
void pushdown(int p)//向下更新 
{
	if(tr[p].add!=0)
	{
		tr[lc].add+=tr[p].add;
		tr[rc].add+=tr[p].add;
		tr[p].add=0;
	}
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

int query(int p,int x,int y)
{
	if(x>y) return 0;
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].mx;
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(y<=m) return query(lc,x,y);
	if(x>m) return query(rc,x,y);
	return max(query(lc,x,y),query(rc,x,y));
}

void updatelr(int p,int x,int y,int k)
{
	if(x<=tr[p].l&&tr[p].r<=y)
	{
		tr[p].mx+=k;
		tr[p].add+=k;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(x<=m) updatelr(lc,x,y,k);
	if(y>m) updatelr(rc,x,y,k);
	pushup(p);	
} 

void solve()
{
	cin>>n>>q;
	for(int i=1;i<=q;i++) 
	{
		cin>>l[i]>>r[i]>>x[i];
		a[l[i]]+=x[i];
		a[r[i]+1]-=x[i];
	}
	ans=0;
	for(int i=1;i<=n;i++) a[i]+=a[i-1],ans=max(ans,a[i]);
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		ans=min(ans,max({query(1,l[i],r[i])-x[i],query(1,1,l[i]-1),query(1,r[i]+1,n)}));
		/*
		updatelr(0,l[i],r[i],-x[i]);
		ans=min(ans,query(1,1,n));
		updatelr(0,l[i],r[i],x[i]);
		*/
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
