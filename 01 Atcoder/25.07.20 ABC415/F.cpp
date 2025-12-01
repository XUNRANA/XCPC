#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
#define lc p<<1
#define rc p<<1|1

struct node
{
    int l,r;//左端点、右端点
    int ls,rs,ss;//左区间起始最长、右区间结束最长、区间内最长
}tr[N<<2];
int a[N];
node merge(node l,node r)
{
    node res;
    res.l=l.l;
    res.r=r.r;
    
    res.ls=l.ls;
    res.rs=r.rs;

    if(a[l.r]==a[r.l])
    {    
        if(l.ls==l.r-l.l+1) res.ls=l.ls+r.ls;
        if(r.rs==r.r-r.l+1) res.rs=r.rs+l.rs;
    }
    res.ss=max({l.ss,r.ss,res.ls,res.rs});
    if(a[l.r]==a[r.l]) res.ss=max(res.ss,l.rs+r.ls);
    
    return res;
}
void build(int p,int l,int r)
{
    tr[p]={l,r,1,1,1};
    if(l==r) return ;
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    tr[p]=merge(tr[lc],tr[rc]);
}
void update(int p,int i,int x)
{
    if(tr[p].l==i&&tr[p].r==i) 
    {
        a[i]=x;
        return ;
    }

    int m=tr[p].l+tr[p].r>>1; 
    if(i<=m) update(lc,i,x);
    else update(rc,i,x);
    tr[p]=merge(tr[lc],tr[rc]);
}
node query(int p,int l,int r)
{
    if(l<=tr[p].l&&tr[p].r<=r) return tr[p];
    int m=tr[p].l+tr[p].r>>1; 
    if(r<=m) return query(lc,l,r);
    if(l>m) return query(rc,l,r);
    return merge(query(lc,l,r),query(rc,l,r));
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
    {
        char ch;
        cin>>ch;
        a[i]=ch-'a';
    }
    build(1,1,n);

    // for(int i=1;i<=4*n;i++) cout<<i<<" "<<tr[i].l<<" "<<tr[i].r<<" "<<tr[i].ls<<" "<<tr[i].rs<<" "<<tr[i].ss<<"\n";

    while(q--)
    {
        int op;
        cin>>op;
        if(op==1) 
        {
            int i;
            char x;
            cin>>i>>x;
            update(1,i,x-'a');
            // for(int i=1;i<=4*n;i++) cout<<i<<" "<<tr[i].l<<" "<<tr[i].r<<" "<<tr[i].ls<<" "<<tr[i].rs<<" "<<tr[i].ss<<"\n";

        }
        else 
        {
            int x,y;
            cin>>x>>y;
            node res=query(1,x,y);
            cout<<res.ss<<"\n";
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

