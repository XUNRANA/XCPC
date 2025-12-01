#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int a[100010];
int b[100010];
bool ck(int x)
{
    int mi=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]-x+b[i-1];
        if(i>=m)
        {
            mi=min(mi,b[i-m]);
            if(b[i]-mi>=0) return 1;
        }
    }
    return 0;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],a[i]*=1000;
    int l=1,r=2000000;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(ck(mid)) l=mid+1;
        else r=mid-1;
    }
    l--;
    cout<<l<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
