#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    cin>>n;
    int ans=0;
    int mi=1e7;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        ans+=x;
        mi=min(mi,x);
    }
    cout<<ans-mi*n<<"\n";
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