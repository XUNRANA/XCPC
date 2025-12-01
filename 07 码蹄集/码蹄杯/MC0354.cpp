#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
#define lc p<<1
#define rc p<<1|1
#define inf 0x3f3f3f3f3f3f3f3f 
struct node
{
    int l,r,s,lz1,lz2;
}tr[N<<2];

void pushup(int p)
{
    tr[p].s=tr[lc].s+tr[rc].s;
}

void lazy(int p,int op,int x)
{
    if(op==1)
    {
        tr[p].s=(tr[p].r-tr[p].l+1)*x;
        tr[p].lz1=x;
        tr[p].lz2=0;
    }
    else
    {
        tr[p].lz2+=x;
        tr[p].s+=(tr[p].r-tr[p].l+1)*x;
    }
}
void pushdown(int p)
{
    if(tr[p].lz1!=inf)
    {
        lazy(lc,1,tr[p].lz1);
        lazy(rc,1,tr[p].lz1);
        tr[p].lz1=inf;
    }
    
    if(tr[p].lz2!=0)
    {
        lazy(lc,2,tr[p].lz2);
        lazy(rc,2,tr[p].lz2);
        tr[p].lz2=0;
    }
}


void build(int p,int l,int r)
{
    tr[p]={l,r,0,inf,0};
    if(l==r) return ;
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(p);
}

//1:[l,r]-->x
//2:[l,r]--> +x
void up(int p,int l,int r,int op,int x)
{
    if(tr[p].l>=l&&tr[p].r<=r) 
    {
        lazy(p,op,x);
        return ;
    }
    int m=tr[p].l+tr[p].r>>1;
    pushdown(p);
    if(l<=m) up(lc,l,r,op,x);
    if(r>m) up(rc,l,r,op,x);
    pushup(p);
}
int query(int p,int l,int r)
{
    if(tr[p].l>=l&&tr[p].r<=r) return tr[p].s;
    int m=tr[p].l+tr[p].r>>1;
    pushdown(p);
    int sum=0;
    if(l<=m) sum+=query(lc,l,r);
    if(r>m) sum+=query(rc,l,r);
    pushup(p);
    return sum;
}
void solve()
{
    int n,m,op,l,r,x;
    cin>>n>>m;
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        cin>>op;
        if(op==3) 
        {
            cin>>l>>r;
            cout<<query(1,l,r)<<"\n";
        }
        else
        {
            cin>>l>>r>>x;
            up(1,l,r,op,x);
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
