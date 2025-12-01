#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
#define P 1000000007
#define lc p<<1
#define rc p<<1|1
struct node
{
    int l,r;
    int c[25];
}tr[N<<2];
int a[N];



int pr[]={2,3,5,7,11,13,17,19,23,29, 31,37,41,43,47,53,59,61,67,71, 73,79,83,89,97};

void add(int p,int i)
{
    int c2=0;
    int c3=0;
    int c5=0;
    int c7=0;
    int x=a[i];
    while(x%2==0) c2++,x/=2;
    while(x%3==0) c3++,x/=3;
    while(x%5==0) c5++,x/=5;
    while(x%7==0) c7++,x/=7;
    tr[p].c[0]+=c2;
    tr[p].c[1]+=c3;
    tr[p].c[2]+=c5;
    tr[p].c[3]+=c7;
    if(x!=1) for(int j=0;j<25;j++) if(x==pr[j]) tr[p].c[j]++;
}
void pushup(int p)
{
    for(int i=0;i<25;i++)
    tr[p].c[i]=tr[lc].c[i]+tr[rc].c[i];
}
void build(int p,int l,int r)
{
    tr[p].l=l;
    tr[p].r=r;
    for(int i=0;i<25;i++) tr[p].c[i]=0;
    add(p,l); 
    if(l==r) return ;
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(p);
}

node query(int p,int l,int r)
{
    if(l<=tr[p].l&&tr[p].r<=r) return tr[p];
    int m=tr[p].l+tr[p].r>>1;
    if(r<=m) return query(lc,l,r);
    if(l>m) return query(rc,l,r);

    node rl=query(lc,l,r);
    node rr=query(rc,l,r);
    for(int i=0;i<25;i++) rl.c[i]+=rr.c[i];
    rl.r=rr.r;
    return rl;
}

void update(int p,int l,int r,int x)
{
    if(tr[p].l==l&&tr[p].r==r)
    {
        for(int i=0;i<25;i++) tr[p].c[i]=0;
        a[l]=x;
        add(p,l); 
        return ;
    }
    int m=tr[p].l+tr[p].r>>1;
    if(r<=m) update(lc,l,r,x);
    else update(rc,l,r,x);
    pushup(p);
}

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

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    int q;
    cin>>q;
    while(q--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
        {
            node t=query(1,x,y);
            int ans=1;
            for(int i=0;i<25;i++) if(t.c[i]) ans=ans*(ksm(pr[i],t.c[i]+1)-1+P)%P*inv(pr[i]-1)%P;
            cout<<ans<<"\n";
        }
        else update(1,x,x,y);
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
