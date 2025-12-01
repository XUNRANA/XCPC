#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n;
vector<int>g[200010];
int in[200010];
int f[200010];
void dfs(int u,int fa)
{
    f[u]=fa;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}
int ksm(int a,int b)
{
    if(b<0) return 1;
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
} 
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) in[i]=0,g[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        in[v]++;
        in[u]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    
    int p1=0,p2=0,cnt=0;
    for(int i=2;i<=n;i++) 
    if(in[i]==1) 
    {
        cnt++;
        if(!p1) p1=i;
        else p2=i;
    }

    if(cnt>2) cout<<"0\n";
    else if(cnt==1) cout<<ksm(2,n)<<"\n";
    else 
    {
        int l1=0;
        while(p1) p1=f[p1],l1++;
        int l2=0;
        while(p2) p2=f[p2],l2++;
        if(l1==l2) 
        {
            cout<<ksm(2,2*l1-n+1)<<"\n";
        }
        else
        {
            if(l1>l2) swap(l1,l2);
            int l=l1+l2-n;
            cout<<(ksm(2,l2-(l1-l))+ksm(2,l2-(l1-l)-1))%P<<"\n";
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
    return 0;
}