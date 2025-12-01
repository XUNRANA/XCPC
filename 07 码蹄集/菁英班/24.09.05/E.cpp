#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
#define lc p<<1
#define rc p<<1|1
int n,m,a[N],op,l,r,x;
struct node
{
	int l,r,lz;
	vector<int>v;
}tr[N<<2];
node merge(node l,node r)
{
	node res;
	res.l=l.l;
	res.r=r.r;
	res.lz=0;
	res.v.clear();
	sort(l.v.begin(),l.v.end(),greater<int>());
	sort(r.v.begin(),r.v.end(),greater<int>());
	int i=0,j=0,li=l.v.size(),lj=r.v.size();
	while(i<li&&j<lj&&res.v.size()<36)
	{
		if(l.v[i]>r.v[j])
		{
			res.v.push_back(l.v[i]);
			i++;
		}
		else
		{
			res.v.push_back(r.v[j]);
			j++;
		}
	}
	while(i<li&&res.v.size()<36) res.v.push_back(l.v[i++]);
	while(j<lj&&res.v.size()<36) res.v.push_back(r.v[j++]);
	
	return res;
}
void build(int p,int l,int r)
{
	if(l==r) 
	{
		tr[p].l=l;
		tr[p].r=r;
		tr[p].lz=0;
		tr[p].v.push_back(a[l]);
		return ;
	}
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	tr[p]=merge(tr[lc],tr[rc]);
}
void pushdown(int p)
{
	if(tr[p].lz!=0)
	{
		for(auto &i:tr[lc].v) i+=tr[p].lz;
		for(auto &i:tr[rc].v) i+=tr[p].lz;
		tr[lc].lz+=tr[p].lz;
		tr[rc].lz+=tr[p].lz;
		tr[p].lz=0;
	}
}
void update(int p,int l,int r,int x)
{
	if(tr[p].l>=l&&tr[p].r<=r)
	{
		for(auto &i:tr[p].v) i+=x;
		tr[p].lz+=x;
		return ;
	}
	pushdown(p);
	int mid=tr[p].l+tr[p].r>>1;
	if(l<=mid) update(lc,l,r,x);
	if(r>mid) update(rc,l,r,x);
	tr[p]=merge(tr[lc],tr[rc]);
}

node query(int p,int l,int r)
{
	if(tr[p].l>=l&&tr[p].r<=r) return tr[p];
	pushdown(p);
	int mid=tr[p].l+tr[p].r>>1;
	if(r<=mid) return query(lc,l,r);
	if(l>mid) return query(rc,l,r);
	return merge(query(lc,l,r),query(rc,l,r));
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	
	for(int i=1;i<=m;i++)
	{
		cin>>op;
		if(op==2)
		{
			cin>>l>>r;
			if(l==r) 
			{
				cout<<"-1\n";
				continue;
			}
			int ans=0;
			vector<int>res=query(1,l,r).v;
			for(int i=0;i<res.size();i++)
			{
				for(int j=i+1;j<res.size();j++)
				{
					ans=max(ans,res[i]&res[j]);
				}
			}
			cout<<ans<<"\n"; 
		}
		else 
		{
			cin>>l>>r>>x;
			update(1,l,r,x);
		}
	}
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
