#include <bits/stdc++.h>
using namespace std;
#define int long long
int fa[200010];
int cnt[200010];
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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) fa[i]=i,cnt[i]=0;
    
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        merge(a,b);
        cnt[a]++;
        cnt[b]++;
    }

    for(int i=1;i<=n;i++) 
    if(cnt[i]>2)
    {
        cout<<"NO\n";
        return ;
    }
    map<int,int>mp;
    for(int i=1;i<=n;i++) mp[find(i)]++;

    for(auto i:mp)
    {
        if(i.second&1) 
        {
            cout<<"NO\n";
            return ;
        }
    }
    cout<<"YES\n";
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