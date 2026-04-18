#include <bits/stdc++.h>
using namespace std;
//N<=1e4
int n;
int ans;
int a[100010];
int b[100010];
bool ck()
{
    for(int i=1;i<=n;i++) if(a[b[i]]!=b[a[i]]) return 0;
    return 1;
}
void dfs(int idx)
{
    if(idx>n) 
    {
        if(ck()) ans++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        b[idx]=i;
        dfs(idx+1);
    }
}
void solve()
{
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
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