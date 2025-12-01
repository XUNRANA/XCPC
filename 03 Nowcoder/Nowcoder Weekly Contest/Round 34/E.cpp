#include <bits/stdc++.h>
using namespace std;
int n,u,v,vt[100010];
string s;
vector<int>g[100010];
int main()
{
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    set<char>st[2];
    vector<int>ans[2];
    int f=1;
    st[f].insert(s[1]);
    ans[f].push_back(1);
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        queue<int>qt;
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            vt[u]=1;
            for(auto v:g[u])
            {
                if(vt[v]) continue;
                st[f^1].insert(s[v]);
                ans[f^1].push_back(v);
                qt.push(v);
            }
        }
        q=qt;
        f^=1;
    }
    if(st[0].count('d')&&st[1].count('d')||st[0].count('p')&&st[1].count('p')) cout<<"-1\n";
    else
    {
        if(!st[0].count('d'))
        {
            for(auto i:ans[0]) s[i]='p';
            for(auto i:ans[1]) s[i]='d';
        }
        else
        {
            for(auto i:ans[0]) s[i]='d';
            for(auto i:ans[1]) s[i]='p';
        }
        cout<<s.substr(1);
    }
}
