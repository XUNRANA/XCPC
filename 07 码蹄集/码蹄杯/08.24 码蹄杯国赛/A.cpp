#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--)
    {
        int op,i,x;
        cin>>op>>i>>x;
        if(op==1) a[i]+=x;
        else a[i]-=x;
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}