#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,nq;
vector<int>idx[100010];
vector<array<int,3>>que[100010];
int ans[1000010];

int tr[1000010];
int lowbit(int x)
{
    return x&-x;
}
void add(int i,int x)
{
    while(i<=1e6)
    {
        tr[i]+=x;
        i+=lowbit(i);
    }
}
int query(int l,int r)
{
    int ans=0;
    while(r)
    {
        ans+=tr[r];
        r-=lowbit(r);
    }
    l--;
    while(l)
    {
        ans-=tr[l];
        l-=lowbit(l);
    }
    return ans;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;//0≤Ai,X≤100000
        x++;
        idx[x].push_back(i);
    }
    for(int i=1;i<=q;i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        x++;
        que[x].push_back({l,r,i});
    }

    for(int i=100001;i>=1;i--)
    {
        for(auto j:idx[i]) add(j,1);
        for(auto [l,r,j]:que[i])
        {
            ans[j]=query(l,r);
        }
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
