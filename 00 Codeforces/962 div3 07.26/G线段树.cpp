#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc p<<1
#define rc p<<1|1
#define N 200010
struct node
{
	int mi,cnt,lz;
}tr[N<<2];
void pushup(int p)
{
	if(tr[lc].mi<tr[rc].mi)
	{
		tr[p].mi=tr[lc].mi;
		tr[p].cnt=tr[lc].cnt;
	}
	else if(tr[rc].mi<tr[lc].mi)
	{
		tr[p].mi=tr[rc].mi;
		tr[p].cnt=tr[rc].cnt;
	}
	else 
	{
		tr[p].mi=tr[lc].mi;
		tr[p].cnt=tr[lc].cnt+tr[rc].cnt;
	}
}
void build(int p,int l,int r)
{
	tr[p]={0,1,0};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}

void pushdown(int p)
{
	if(tr[p].lz!=0)
	{
		tr[lc].mi+=tr[p].lz;
		tr[lc].lz+=tr[p].lz;
		
		tr[rc].mi+=tr[p].lz;
		tr[rc].lz+=tr[p].lz;
		
		tr[p].lz=0;
	}
}
void update(int p,int tl,int trr,int l,int r,int add)
{
	if(l>r) return ;
	if(l<=tl&&trr<=r)
	{
		tr[p].mi+=add;
		tr[p].lz+=add;
		return ;
	}
	pushdown(p);
	int m=tl+trr>>1;
	if(l<=m) update(lc,tl,m,l,r,add);
	if(r>m) update(rc,m+1,trr,l,r,add);
	pushup(p);
}

node query(int p,int tl,int tri,int l,int r)
{
	if(l<=tl&&tri<=r) return tr[p];
	
	pushdown(p);
	
	int m=tl+tri>>1;
	
	if(r<=m) return query(lc,tl,m,l,r);
	
	if(l>m) return query(rc,m+1,tri,l,r);
	
	node n1,n2,n3;
	
	n1=query(lc,tl,m,l,r);
	
	n2=query(rc,m+1,tri,l,r);
	
	if(n1.mi<n2.mi)
	{
		n3.mi=n1.mi;
		n3.cnt=n1.cnt;
	}
	else if(n2.mi<n1.mi)
	{
		n3.mi=n2.mi;
		n3.cnt=n2.cnt;
	}
	else
	{
		n3.mi=n1.mi;
		n3.cnt=n1.cnt+n2.cnt;
	}
	return n3;
} 
vector<int>s[N],f[N];
void solve()
{
	int n,m,a,b,ans;
	cin>>n>>m;
	build(1,1,n);
	for(int i=1;i<=n;i++) 
	{
		s[i].clear();
		f[i].clear();
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		update(1,1,n,a,b-1,1);
		s[a].push_back(b);
		f[b].push_back(a);
	}
	ans=min(n-1,n-query(1,1,n,1,n).cnt);
	for(int i=1;i<=n;i++)
	{
		for(auto j:s[i])
		{
			update(1,1,n,i,j-1,-1);
			update(1,1,n,j,n,1);
			update(1,1,n,1,i-1,1); 
		}
		for(auto j:f[i])
		{
			update(1,1,n,i,n,-1);
			update(1,1,n,1,j-1,-1); 
			update(1,1,n,j,i-1,1);
		}
		if(query(1,1,n,1,n).mi==0) ans=min(ans,n-query(1,1,n,1,n).cnt);
	}
	cout<<ans<<"\n";

	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	
}
