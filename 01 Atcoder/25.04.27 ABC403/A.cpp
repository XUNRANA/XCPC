#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,x;
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(i&1) s+=x;
    }
    cout<<s<<"\n";
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