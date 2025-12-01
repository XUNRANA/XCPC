#include <bits/stdc++.h>
using namespace std;
#define lc p<<1
#define rc p<<1|1
#define N 200010
int n,k,a[N];
long long ans;
struct node
{
	int l,r,mn,c,lz;
}tr[N<<2];
node merge(node l,node r)
{
	node res;
	res.l=l.l;
	res.r=r.r;
	res.mn=min(l.mn,r.mn);
	res.c=res.lz=0;
	if(res.mn==l.mn) res.c+=l.c;
	if(res.mn==r.mn) res.c+=r.c;
	return res;
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		tr[p]={l,r,0,1,0};
		return ;
	}
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	tr[p]=merge(tr[lc],tr[rc]);
}
void pushdown(int p)
{
	if(tr[p].lz!=0)
	{
		tr[lc].mn+=tr[p].lz;
		tr[lc].lz+=tr[p].lz;
		tr[rc].mn+=tr[p].lz;
		tr[rc].lz+=tr[p].lz;
		tr[p].lz=0;
	}
}
void update(int p,int l,int r,int x)
{
	if(l>r) return ;
	if(tr[p].l>=l&&tr[p].r<=r)
	{
		tr[p].mn+=x;
		tr[p].lz+=x;
		return ;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(l<=m) update(lc,l,r,x);
	if(r>m) update(rc,l,r,x);
	tr[p]=merge(tr[lc],tr[rc]);
}
node query(int p,int l,int r)
{
	if(tr[p].l>=l&&tr[p].r<=r) return tr[p];
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(r<=m) return query(lc,l,r);
	if(l>m) return query(rc,l,r);
	return merge(query(lc,l,r),query(rc,l,r));
}

void solve()
{
	ans=0;
	cin>>n>>k;
	build(1,1,n);
	map<int,vector<int>>mp;
	unordered_map<int,int>r; 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		auto &v = mp[a[i]];
		v.push_back(i);
		if(v.size()<k)//不到k个 
		{
			update(1,i,n,1);
			r[i]=n;
		}
		else if(v.size()==k)
		{
			update(1,i,v[v.size()-k]-1,1);
			r[i]=v[v.size()-k]-1;
		}
		else  
		{      
		    update(1,v[v.size()-k-1],n,1);//大于k个的位置全无效 
			update(1,i,v[v.size()-k]-1,1);
			r[i]=v[v.size()-k]-1;
		}
		
		if(v.size()>=2)//消除上一次的影响 
		{
			update(1,v[v.size()-2],r[v[v.size()-2]],-1);
		}
		
		if(query(1,i,n).mn==0) ans+=query(1,i,n).c;
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
