#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,q,a,p[510],d[510];

int fx(int x)
{
    for(int i=1;i<=n;i++) if(x>=p[i-1]&&x<=p[i])
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    cin>>q;
    while(q--)
    {
        cin>>a;
        cout<<fx(a)<<"\n";
    }
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