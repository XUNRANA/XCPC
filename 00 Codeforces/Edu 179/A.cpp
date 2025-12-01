#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[4];
void solve()
{
    int x;
    cin>>x;
    a[1]=a[2]=a[3]=0;
    int ans=0;
    while(1)
    {
        sort(a+1,a+1+3);
        if(a[1]==x) break;
        a[1]=min(a[2]*2+1,x);
        ans++;
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