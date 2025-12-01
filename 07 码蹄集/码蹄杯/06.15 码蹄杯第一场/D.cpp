#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000010
#define lc p<<1
#define rc p<<1|1
struct node
{
    //val为区间[l,r]最大值的下标（多个取最小）
    //size为区间[l,r]中还存在的数
    int l,r,val,size;
}tr[N<<2];
int a[N];
int ans[N];
void pushup(int p)
{
    if(a[tr[lc].val]>=a[tr[rc].val]) tr[p].val=tr[lc].val;
    else tr[p].val=tr[rc].val;
    tr[p].size=tr[lc].size+tr[rc].size;
}
void build(int p,int l,int r)
{
    tr[p]={l,r,l,1};
    if(l==r) return ;
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(p);
}
//前k个数里面最大值的下标（多个取最小值）
int findmax(int p,int l,int r,int k)
{
    if(l==r) return l;
    int m=l+r>>1;
    if(k<=tr[lc].size) return findmax(lc,l,m,k);
    
    int tmp=findmax(rc,m+1,r,k-tr[lc].size);
    if(a[tr[lc].val]>=a[tmp]) return tr[lc].val;
    else return tmp;
}
//删除第x个数，更新size
void change(int p,int l,int r,int x)
{
    if(l==r)
    {
        tr[p].size=0;
        return ;
    }
    int m=l+r>>1;
    if(x<=m) change(lc,l,m,x);
    else change(rc,m+1,r,x);
    pushup(p);
}
//前x个有多少个数比第x个数小
int count(int p,int l,int r,int x)
{
    if(l==r) return tr[p].size;
    int m=l+r>>1;
    if(x<=m) return count(lc,l,m,x);
    else return tr[lc].size+count(rc,m+1,r,x);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        int tmp=findmax(1,1,n,m+1);
        ans[i]=a[tmp];
        a[tmp]=-1;
        change(1,1,n,tmp);
        m-=count(1,1,n,tmp);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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