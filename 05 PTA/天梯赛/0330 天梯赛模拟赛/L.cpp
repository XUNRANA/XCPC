#include <bits/stdc++.h>
using namespace std;
#define int long long
int tr[100010];
int a[100010];
int n,m;
int lowbit(int x)
{
    return x&-x;
}
void add(int i,int x)
{
    while(i<=n)
    {
        tr[i]+=x;
        i+=lowbit(i);
    }
}
int query(int l,int r)
{
    if(r-l+1<3) return 0;
    l++;
    r--;
    int res=0;
    while(r)
    {
        res+=tr[r];
        r-=lowbit(r);
    }
    l--;
    while(l)
    {
        res-=tr[l];
        l-=lowbit(l);
    }
    return res;
}
int ck(int idx)
{
    if(idx<=1||idx>=n) return 0;
    if(a[idx]>a[idx-1]&&a[idx]>a[idx+1]) return 1;
    return 0;
}
void update(int k,int h)
{
    vector<int>c,d;
    // k-1 k k+1
    for(int i=k-1;i<=k+1;i++) c.push_back(ck(i));
    a[k]=h;
    for(int i=k-1;i<=k+1;i++) d.push_back(ck(i));
    for(int i=0;i<3;i++)//0 1 2    k-1 k k+1 
    // cout<<c[i]<<" "<<d[i]<<"\n";
    if(c[i]!=d[i])
    {
        if(c[i]) add(k-1+i,-1);
        else add(k-1+i,1);
    }

}

void solve() 
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n-1;i++) if(a[i]>a[i-1]&&a[i]>a[i+1]) add(i,1);
    while(m--)
    {
        int op,l,r;
        cin>>op>>l>>r;
        if(n<10)
        {
            if(op==1) a[l]=r;
            else 
            {
                int ans=0;
                for(int i=l+1;i<=r-1;i++) if(a[i]>a[i-1]&&a[i]>a[i+1]) ans++;
                cout<<ans<<"\n";
            }
        }
        else
        {   
            if(op==1) update(l,r);
            else cout<<query(l,r)<<"\n";
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