#include <bits/stdc++.h>
using namespace std;
#define int long long

int t[400010];
int lowbit(int x)
{
    return x&-x;
}
void add(int i,int x)
{
    while(i<=4e5)
    {
        t[i]+=x;
        i+=lowbit(i);
    }
}
int query(int l,int r)
{
    int res=0;
    while(r)
    {
        res+=t[r];
        r-=lowbit(r);
    }

    l--;
    while(l)
    {
        res-=t[l];
        l-=lowbit(l);
    }
    return res;
}

int n,x[100010],r[100010];
struct node
{
    int l,r;
}p[100010];
bool cmp(node p1,node p2)
{
    if(p1.l==p2.l) return p1.r<p2.r;
    return p1.l<p2.l;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i],x[i]+=2e5+1;
    for(int i=1;i<=n;i++) cin>>r[i];
    for(int i=1;i<=n;i++) 
    {
        p[i].l=x[i]-r[i];
        p[i].r=x[i]+r[i];
    }
    sort(p+1,p+1+n,cmp);
    priority_queue<int,vector<int>,greater<int>>q;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=query(p[i].l,p[i].r);
        add(p[i].r,1);
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
    return 0;
}