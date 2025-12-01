#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int n,m;
bool ck(int x)
{
    int s=0;
    for(int i=1;i<=n;i++)
    {
        s+=a[i]/x;
        if(s>m) return 0;
    }
    return 1;
}
void solve()
{
    cin>>n>>m;
    int s=0;
    for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    int l=1,r=s;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(ck(mid)) r=mid-1;
        else l=mid+1;
    }
    l=max(l,1ll);
    cout<<l<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}