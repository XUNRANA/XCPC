#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
set<int>g[100010];
void solve() 
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++) g[i].clear();
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    priority_queue<int>q;
    for(int i=1;i<=n;i++) if(g[i].size()==1) q.push(i);
    int now=n;
    while(now)
    {
        if(!q.empty()&&q.top()==now)
        { 
            for(auto v:g[now])
            {
                g[v].erase(now);
                if(g[v].size()==1) q.push(v);
                else if(g[v].size()==0&&v)
                {
                    cout<<"0\n";
                    return ;
                } 
            }
            now--;
            q.pop();  
        }
        else
        {
            for(auto v:g[now])
            {
                g[v].erase(now);
                if(g[v].size()==1) q.push(v);
                else if(g[v].size()==0&&v)
                {
                    cout<<"0\n";
                    return ;
                } 
            }
            now--;
        }
    }
    cout<<"1\n";
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