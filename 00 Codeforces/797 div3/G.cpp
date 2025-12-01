#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,k,x,a[100010];
map<int,int>mp;
void add(int i,int x)
{
    mp[i]=x;
    auto it=mp.find(i);
    if(it!=mp.begin()&&prev(it)->second<=x)
    {
        mp.erase(it);
        return ;
    }
    while(next(it)!=mp.end()&&next(it)->second>=x)
    {
        mp.erase(next(it));
    }
}
void solve() 
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    mp.clear();
    for(int i=1;i<=n;i++) add(i,a[i]);
    while(q--)
    {
        cin>>x>>k;
        a[x]-=k;
        add(x,a[x]);
        cout<<mp.size()<<" ";
    }
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