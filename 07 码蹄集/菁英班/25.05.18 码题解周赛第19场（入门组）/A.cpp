#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,b[100010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(b+1,b+1+n);
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        if(b[i]+1-(i-1)<0)
        {
            cout<<"0\n";
            return ;
        }
        ans=ans*(b[i]+1-(i-1))%P;
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