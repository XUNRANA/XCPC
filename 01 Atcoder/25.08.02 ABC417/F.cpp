#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
#define P 998244353
#define lc p<<1
#define rc p<<1|1
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
int inv(int x)
{
    return ksm(x,P-2);
}
struct node
{
    int l,r,s,lz;
}tr[N<<2];
int a[N];
node merge(node l,node r)
{
    node res;
    res.l=l.l;
    res.r=r.r;
    res.s=(l.s+r.s)%P;
    res.lz=-1;
    return res;
}
void pushdown(int p)
{
    if(tr[p].lz!=-1)
    {
        tr[lc].lz=tr[rc].lz=tr[p].lz;
        tr[p].lz=-1;
        tr[lc].s=(tr[lc].r-tr[lc].l+1)*tr[lc].lz%P;
        tr[rc].s=(tr[rc].r-tr[rc].l+1)*tr[rc].lz%P;
    }
}
void build(int p,int l,int r)
{
    tr[p]={l,r,a[l],-1};
    if(l==r) return ;
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    tr[p]=merge(tr[lc],tr[rc]);
}
node query(int p,int l,int r)
{
    if(l<=tr[p].l&&tr[p].r<=r)
    {
        return tr[p];
    }
    int m=tr[p].l+tr[p].r>>1;
    pushdown(p);
    if(r<=m) return query(lc,l,r);
    if(l>m) return query(rc,l,r);
    return merge(query(lc,l,r),query(rc,l,r));
}
void update(int p,int l,int r,int x)
{
    if(l<=tr[p].l&&tr[p].r<=r)
    {
        tr[p].lz=x;
        tr[p].s=(tr[p].r-tr[p].l+1)*x%P;
        return ;
    }
    int m=tr[p].l+tr[p].r>>1;
    pushdown(p);
    if(l<=m) update(lc,l,r,x);
    if(r>m) update(rc,l,r,x);

    tr[p]=merge(tr[lc],tr[rc]);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);

    // for(int i=1;i<=n;i++) cout<<query(1,i,i).s<<" ";
    // cout<<"\n";

    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int s=query(1,l,r).s;
        int x=s*inv(r-l+1)%P;
        update(1,l,r,x);

        // cout<<"UPDATE: "<<l<<" "<<r<<" "<<x<<"\n";
        // for(int i=1;i<=n;i++) cout<<query(1,i,i).s<<" ";
        // cout<<"\n";
        // cout<<query(1,l,r).s<<"\n";

    }
    for(int i=1;i<=n;i++) cout<<query(1,i,i).s<<" ";
    cout<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

