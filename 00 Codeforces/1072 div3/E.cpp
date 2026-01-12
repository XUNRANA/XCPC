#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int fa[N],sz[N];
bool act[N];
vector<int> buc[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int calc(int x){return x*(x+1)/2;}
void solve()
{
    int n;
    cin>>n;
    vector<int> p(n+1);
    for(int i=0;i<=n;i++)
    {
        buc[i].clear();
        fa[i]=i;
        sz[i]=1;
        act[i]=0;
    }
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<n;i++) buc[abs(p[i]-p[i+1])].push_back(i);
    int cur=0;
    vector<int> ans(n);
    for(int k=n-1;k>=1;k--)
    {
        for(auto x:buc[k])
        {
            act[x]=1;
            cur+=calc(1);
            if(x>1&&act[x-1])
            {
                int u=find(x),v=find(x-1);
                if(u!=v)
                {
                    cur-=calc(sz[u]);
                    cur-=calc(sz[v]);
                    fa[v]=u;
                    sz[u]+=sz[v];
                    cur+=calc(sz[u]);
                }
            }
            if(x<n-1&&act[x+1])
            {
                int u=find(x),v=find(x+1);
                if(u!=v)
                {
                    cur-=calc(sz[u]);
                    cur-=calc(sz[v]);
                    fa[v]=u;
                    sz[u]+=sz[v];
                    cur+=calc(sz[u]);
                }
            }
        }
        ans[k]=cur;
    }
    for(int i=1;i<n;i++) cout<<ans[i]<<" \n"[i==n-1];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}