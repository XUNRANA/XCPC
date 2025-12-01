#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010];
void solve()
{
    a[1]=5;
    a[2]=2;
    a[3]=0;
    for(int i=4;i<=1000;i++)
    {
        a[i]=(a[i-1]+a[i-2]+a[i-3])%10;
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cout<<a[i];
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