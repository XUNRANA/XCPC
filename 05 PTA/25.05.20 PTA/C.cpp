#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int cnt=0;
    while(1)
    {
        int x;
        cin>>x;
        cnt++;
        if(x==520)
        {
            cout<<cnt<<"\n";
            break;
        }
    }
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