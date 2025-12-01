#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100010];
int d[100010];
int p[100010];

void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++) d[i]=max(a[i+1]-a[i],0ll);
    for(int i=1;i<n;i++) p[i]=d[i]+p[i-1];

    // for(int i=1;i<n;i++) cout<<d[i]<<" ";
    // cout<<"\n";

    // for(int i=1;i<n;i++) cout<<p[i]<<" ";
    // cout<<"\n";

    int k;
    cin>>k;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(l==r) cout<<k<<"\n";
        else
        {
            cout<<p[r-1]-p[l-1]+k<<"\n";
        }
    }
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}