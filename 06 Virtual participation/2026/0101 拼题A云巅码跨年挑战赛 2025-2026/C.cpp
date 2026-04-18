#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,n,x;
    cin>>a>>n;
    cout<<a<<"\n";
    while(n--)
    {
        cin>>x;
        a+=x;
    }
    cout<<a<<"\n";
    

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}