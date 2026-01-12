#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
#define lc p<<1
#define rc p<<1|1
int w[N];
struct node
{
    int l,r,mi; // 维护区间最小值
}tr[N<<2];

void pushup(int p)
{
    tr[p].mi=min(tr[lc].mi,tr[rc].mi);
}
void build(int p,int l,int r)
{
    tr[p]={l,r,0};
    if(l==r)
    {
        tr[p].mi=w[l];
        return ;

    }
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(p);
}

void update(int p,int x,int k) // 单点修改
{
    if(tr[p].l==x&&tr[p].r==x)
    {
        tr[p].mi=k;
        return;
    }
    int m=tr[p].l+tr[p].r>>1;
    if(x<=m) update(lc,x,k);
    else update(rc,x,k);
    pushup(p);
}

int query(int p,int x,int y) // 区间查询最小值
{
    if(x<=tr[p].l&&tr[p].r<=y) return tr[p].mi;
    int m=tr[p].l+tr[p].r>>1;
    int res=2e18; 
    if(x<=m) res=min(res,query(lc,x,y));
    if(y>m) res=min(res,query(rc,x,y));
    return res;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>w[i];
    build(1,1,n);
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int i,x;
            cin>>i>>x;
            update(1,i,x);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            int L=0,R=r-l;
            int ans=0;
            while(L<=R)
            {
                int mid=L+R>>1;
                int val=query(1,l,l+mid);
                if(val==mid)
                {
                    ans=1;
                    break;
                }
                if(val>mid) L=mid+1;
                else R=mid-1;
            }
            cout<<ans<<"\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}