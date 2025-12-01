#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n;
void solve()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        ans=(ans*(x+1)%P+x)%P;
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
}