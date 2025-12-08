#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P=1e9+7;
#define N 200010
int n,x;

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

#define lc p<<1
#define rc p<<1|1
struct node
{
    int l,r,sum,add;
}tr[4*N];
void pushup(int p)
{
    tr[p].sum=(tr[lc].sum+tr[rc].sum)%P;
}
void pushdown(int p)
{
    if(tr[p].add!=-1)
    {
        int x=tr[p].add;
        tr[p].add=-1;
        tr[lc].sum=tr[lc].sum*x%P;
        tr[rc].sum=tr[rc].sum*x%P;
        tr[lc].add=tr[rc].add=x;
    }
}
void build(int p,int l,int r)
{
    tr[p]={l,r,0,-1};
    if(l==r) return ;
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(p);
}
void update(int p,int x,int k)
{
    pushdown(p);
    if(tr[p].l==x&&tr[p].r==x)
    {
        tr[p].sum=(tr[p].sum+k)%P;
        return ;
    }
    int m=tr[p].l+tr[p].r>>1;
    if(x<=m) update(lc,x,k);
    else update(rc,x,k);
    pushup(p);
}
int query(int p,int x,int y)
{
    if(x>y) return 0;
    pushdown(p);
    if(x<=tr[p].l&&tr[p].r<=y) return tr[p].sum;
    int m=tr[p].l+tr[p].r>>1;
    int sum=0;
    if(x<=m) sum=(sum+query(lc,x,y))%P;
    if(y>m) sum=(sum+query(rc,x,y))%P;
    pushup(p);
    return sum;
}
void updatelr(int p,int x,int y,int k)
{
    if(x>y) return ;
    pushdown(p);
    if(x<=tr[p].l&&tr[p].r<=y) 
    {
        tr[p].sum=tr[p].sum*k%P;
        tr[p].add=k;
        return ;
    }
    int m=tr[p].l+tr[p].r>>1;
    if(x<=m) updatelr(lc,x,y,k);
    if(y>m) updatelr(rc,x,y,k);
    pushup(p);
}

struct node1
{
    int a,i,idx;
}a[N];
bool cmp(node1 a1,node1 a2)
{
    if(a1.a==a2.a) return a1.i<a2.i;
    return a1.a<a2.a;
}
bool cmpi(node1 a1,node1 a2)
{
    return a1.i<a2.i;
}
void solve()
{
    cin>>n>>x;
    int p1=x*inv(100)%P;//min
    int q1=(100-x)*inv(100)%P;//max

    for(int i=1;i<=n;i++) cin>>a[i].a,a[i].i=i;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) 
    {
        if(a[i].a==a[i-1].a) a[i].idx=a[i-1].idx;
        else a[i].idx=a[i-1].idx+1;
    }
    sort(a+1,a+1+n,cmpi);

    build(1,1,n);
    update(1,a[1].idx,1);


    for(int i=2;i<=n;i++)
    {
        int val=a[i].idx;
        int s1=query(1,1,val-1);
        int s2=query(1,val+1,n);
        update(1,val,(s1*q1%P+s2*p1%P)%P);
        updatelr(1,1,val-1,p1);
        updatelr(1,val+1,n,q1);
    }

    int ans=0;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) 
    {
        if(a[i].a==a[i-1].a) continue;
        ans=(ans+a[i].a*query(1,a[i].idx,a[i].idx)%P)%P;
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}