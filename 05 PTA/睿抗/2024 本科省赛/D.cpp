#include <bits/stdc++.h>
using namespace std;
int n,m,u,v;
set<int>g[100010];
int fa[100010];
int c[100010];
int find(int x)
{
    return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    fa[find(x)]=find(y);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        g[i].clear();
        fa[i]=i;
        c[i]=0;
    }
    for(int i=1;i<=m;i++) 
    {
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    queue<int>q;
    for(int i=1;i<=n;i++) if(g[i].size()==1) q.push(i); 
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:g[u])
        {
            g[v].erase(u);
            m--;
            if(g[v].size()==1) q.push(v);
        }
        g[u].clear();
    }



    for(int i=1;i<=n;i++) 
    for(auto v:g[i]) merge(v,i);
    
    map<int,set<int>>mp;
    for(int i=1;i<=n;i++) 
    {
        mp[find(i)].insert(g[i].size());
        c[find(i)]++;
    }

    int cnt=0;
    for(auto i:mp)
    {
        if(c[i.first]<=2) continue;
        if(i.second.size()==1&&*i.second.begin()==2) cnt++;
    }

    if(cnt==1) cout<<"Yes "<<m<<"\n";
    else cout<<"No "<<cnt<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
