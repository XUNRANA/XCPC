#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[110];
int n,q;
void solve() 
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    map<int,int>l,r;
    for(int i=1;i<=q;i++)
    {
        int b,x,y;
        cin>>b>>x>>y;
        if(l.count(b))
        {
            l[b]=max(l[b],x);
            r[b]=min(r[b],y);
        }
        else
        {
            l[b]=x;
            r[b]=y;
        }
    }
    int ans=0;
    // for(auto i:l) cout<<i.first<<" "<<i.second<<"\n";
    // for(auto i:r) cout<<i.first<<" "<<i.second<<"\n";
    for(int i=1;i<=n;i++)
    if(l.count(i))
    {
        if(l[i]>r[i]) 
        {
            cout<<"-1\n";
            return ;
        }
        else if(a[i]<l[i]) ans+=l[i]-a[i];
        else if(a[i]>r[i]) ans+=a[i]-r[i];
    }
    cout<<ans<<"\n";

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
