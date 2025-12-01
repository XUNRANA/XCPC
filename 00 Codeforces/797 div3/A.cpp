#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    cin>>n;
    if(n%3==0)
    {
        cout<<n/3<<" "<<n/3+1<<" "<<n/3-1<<"\n";
    }
    else if(n%3==1)
    {
        cout<<n/3<<" "<<n/3+2<<" "<<n/3-1<<"\n";
    }
    else
    {
        cout<<n/3+1<<" "<<n/3+2<<" "<<n/3-1<<"\n";
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