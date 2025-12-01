#include <bits/stdc++.h>
using namespace std;
#define int long long
int tr[200010];
int n,x;
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
void solve() 
{
    
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) tr[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        ans+=query(x,n);
        add(x,1);
    }
    cout<<ans<<'\n';
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}