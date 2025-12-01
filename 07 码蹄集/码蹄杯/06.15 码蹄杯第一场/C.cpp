#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,q,a[500010];
long long p[500010];
long long p1[500010];
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) p[i]=(p[i-1]+a[i]*i%P)%P;
    for(int i=1;i<=n;i++) p1[i]=(p1[i-1]+a[i])%P;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int s=(p[r]-p[l-1]+P)%P;
        int s1=(p1[r]-p1[l-1]+P)%P;
        int ans=(s-s1*(l-1)%P+P)%P;
        cout<<ans<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}