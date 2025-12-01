#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200010];
void solve()
{
    int n;
    cin>>n;
    int j=1;
    for(int i=1;i<=n/2;i++)
    {
        a[i]=j++;
        a[n+1-i]=j++;
    }
    if(n&1) a[(n+1)/2]=j;
    for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
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