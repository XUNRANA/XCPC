#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
#define lc p<<1
#define rc p<<1|1
struct node
{
    int l,r,mx1,mx2,lz;
}tr[N<<2];
int a[N];
node merge(node l,node r)
{
    // cout<<l.l<<" "<<l.r<<" "<<l.mx1<<" "<<l.mx2<<"\n";
    // cout<<r.l<<" "<<r.r<<" "<<r.mx1<<" "<<r.mx2<<"\n\n";

    node res;
    res.l=l.l;
    res.r=r.r;
    
    set<int>st;
    st.insert(l.mx1);
    st.insert(l.mx2);
    st.insert(r.mx1);
    st.insert(r.mx2);
    
    // for(auto i:st) cout<<i<<" ";
    // cout<<"!!\n";
    if(st.size())
    {
        res.mx1=*st.rbegin();
        st.erase(--st.end());
    }
    res.mx2=*st.rbegin();

    res.lz=0;
    return res;
}
void pushdown(int p)
{
    if(tr[p].lz)
    {
        tr[lc].mx1+=tr[p].lz;
        if(tr[lc].mx2) tr[lc].mx2+=tr[p].lz;
        tr[lc].lz+=tr[p].lz;

        tr[rc].mx1+=tr[p].lz;
        if(tr[rc].mx2) tr[rc].mx2+=tr[p].lz;
        tr[rc].lz+=tr[p].lz;

        tr[p].lz=0;
    }
}
void build(int p,int l,int r)
{
    tr[p]={l,r,a[l],0,0};
    if(l==r) return ;
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    tr[p]=merge(tr[lc],tr[rc]);
}
void add(int p,int l,int r,int k)
{
    if(l<=tr[p].l&&tr[p].r<=r)
    {
        tr[p].mx1+=k;
        if(tr[p].mx2) tr[p].mx2+=k;
        tr[p].lz+=k;
        return ;
    }
    int m=tr[p].l+tr[p].r>>1;
    pushdown(p);
    if(l<=m) add(lc,l,r,k);
    if(r>m) add(rc,l,r,k);
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

void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);

    node res=query(1,2,3);
    // cout<<res.mx2<<"???\n";

    // for(int i=1;i<=4*n;i++) cout<<i<<":"<<tr[i].l<<" "<<tr[i].r<<" "<<tr[i].mx1<<" "<<tr[i].mx2<<"\n";
    while(q--)
    {
        int op,l,r,k;
        cin>>op;
        if(op==1) 
        {
            cin>>l>>r>>k;
            add(1,l,r,k);
        }
        else 
        {
            cin>>l>>r;
            node res=query(1,l,r);
            cout<<res.mx2<<"\n";
        }
    }
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}