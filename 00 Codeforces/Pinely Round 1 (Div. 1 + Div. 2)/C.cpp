#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[110];
set<int>st[110];
int in[110];
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear(),st[i].clear(),in[i]=0,st[i].insert(i);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='1') 
            {
                g[i].push_back(j);
                in[j]++;
            }
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);


    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:g[u])
        {
            st[v].insert(st[u].begin(), st[u].end());
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<st[i].size()<<" ";
        for(auto j:st[i]) cout<<j<<" ";
        cout<<"\n"; 
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