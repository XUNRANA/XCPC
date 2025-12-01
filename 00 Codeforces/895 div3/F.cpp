#include <bits/stdc++.h>
using namespace std;

int a[100010];
int c[100010];
int in[100010];
int vt[100010];
vector<int>g[100010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear(),in[i]=vt[i]=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        in[a[i]]++;
        g[i].push_back(a[i]);
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    queue<int>q;
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
    vector<int>ans;
    while(!q.empty())
    {
        int u=q.front();
        vt[u]=1;
        ans.push_back(u);
        q.pop();
        for(auto v:g[u])
        {
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
    for(int i=1;i<=n;i++) 
    if(!vt[i])
    {
        int u=i;
        vector<int>p;
        while(a[u]!=i)
        {
            p.push_back(u);
            vt[u]=1;
            u=a[u];
        }
        vt[u]=1;
        p.push_back(u);

        int mi=1e9;
        for(auto j:p) mi=min(mi,c[j]);

        if(c[p.back()]==mi)
        {
            for(auto j:p) ans.push_back(j);
        }
        else
        {
            for(int j=0;j<p.size();j++) 
            if(c[p[j]]==mi)
            {
                for(int k=j+1;k<p.size();k++) ans.push_back(p[k]);
                for(int k=0;k<=j;k++) ans.push_back(p[k]);
                break;
            }
        }
    }
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
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