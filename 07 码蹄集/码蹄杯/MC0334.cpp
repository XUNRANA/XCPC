#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int a[1000010];
int c[100010];
void solve()
{
    int n;
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        c[x]++;
        mx=max(mx,x);
    }
    int ans=1;
    for(int i=1;i<mx;i++) ans=ans*(c[i]+1)%P;
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
