#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
int n,m;
bool ck(int x)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int d=a[i]-a[i-1];
        if(d<=x) continue;
        else 
        {
            if(d%x==0) cnt+=d/x-1;
            else cnt+=d/x;
            if(cnt>m) return 0;
        }
    }
    return 1;
}
void solve()
{
    cin>>n>>m;
    m++;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=1e8;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(ck(mid)) r=mid-1;
        else l=mid+1; 
    }
    cout<<l<<"\n";
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