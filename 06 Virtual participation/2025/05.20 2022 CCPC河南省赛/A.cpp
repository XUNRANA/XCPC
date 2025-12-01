#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    if(n>10) 
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<"1";
        int j=0;
        n--;
        while(n--)
        {
            if(j==1) j++;
            cout<<j++;
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
