#include <bits/stdc++.h>
using namespace std;
int f;
string s,t;
int n,m;
void dfs(int i)
{
    if(s.find(t)!=string::npos) f=1;
    if(i==n) return ;
    if(s[i]=='?')
    {
        for(int j=0;j<26;j++)
        {
            s[i]=char('a'+j);
            dfs(i+1);
            s[i]='?';
        }
    }
    else dfs(i+1);
}
void solve()
{
    cin>>s>>t;
    n=s.size();
    m=t.size();
    dfs(0);
    if(f) cout<<"Yes\n";
    else cout<<"No\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}