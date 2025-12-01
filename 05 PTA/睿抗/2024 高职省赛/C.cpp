#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n;
    cin>>n;
    int s0=0;
    int s1=0;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        if(x>0) s1++;
        else s0++;
    }
    cout<<min(s1,s0);

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

