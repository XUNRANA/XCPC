#include <bits/stdc++.h>
using namespace std;


vector<int>g[1000010];
int p[1000010][26];
int sc[1000010];
int pc[1000010];
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) 
    {
        sc[i]=pc[i]=0;
        g[i].clear();
        for(int j=0;j<26;j++) p[i][j]=0;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u][s[v]-'A']++;
        p[v][s[u]-'A']++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    if(s[i]=='C')
    {
        for(auto v:g[i])
        {
            if(s[v]=='C') 
            {
                sc[v]+=p[i]['S'-'A'];
            }
        }
    }
    else if(s[i]=='P')
    {
        for(auto v:g[i])
        {
            if(s[v]=='C') 
            {
                pc[v]+=p[i]['C'-'A']-1;
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++) ans+=1ll*pc[i]*sc[i];
    cout<<ans<<"\n";
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}