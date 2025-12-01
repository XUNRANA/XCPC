#include <bits/stdc++.h>
using namespace std;
#define int long long
int is(int x)
{
    if(x%7==0) return 1;
    while(x)
    {
        if(x%10==7) return 1;
        x/=10;
    }
    return 0;
}
void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!is(i)) ans+=i;
    }
    cout<<ans<<"\n";
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