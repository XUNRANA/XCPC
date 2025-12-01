#include <bits/stdc++.h>
using namespace std;
int n,q;
int dp[1<<12][1010];
int find(int st,int x)
{
    return dp[st][x]==x? x:dp[st][x]=find(st,dp[st][x]);
}
void merge(int st,int u,int v)
{
    if(find(st,u)==find(st,v)) return ;
    dp[st][find(st,u)]=find(st,v);
    for(int i=0;i<12;i++)
    {
        if(st>>i&1)
        {
            merge(st^(1<<i),u,v);
        }
    }
}
bool ck(int st,int u,int v)
{
    return find(st,u)==find(st,v);
}
int query(int u,int v)
{
    int ans=0;
    for(int st=11;st>=0;st--)
    {
        int nans=ans|(1<<st);
        if(ck(nans,u,v)) ans=nans;
    }
    if(ans) return ans;
    else if(ck(0,u,v)) return 0;
    else return -1;
}
void init(int n)
{
    for(int st=0;st<(1<<12);st++) for(int i=1;i<=n;i++) dp[st][i]=i;
}
void solve()
{
    cin>>n>>q;
    init(n);
    long long ans=0;
    while(q--)
    {
        char ch;
        int u,v,w;
        cin>>ch;
        if(ch=='+')
        {
            cin>>u>>v>>w;
            merge(w,u,v);
        }
        else
        {
            cin>>u>>v;
            ans+=query(u,v);
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}