#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,a[200010];
void solve()
{
    cin>>n>>k;
    int now=2;

    for(int i=1;i<=k+1;i++) a[i]=now++;
    for(int i=k+2;i<=n;i++) 
    {
        while(__gcd(now,a[i-1])!=1||__gcd(now,a[i-k-1])==1) now++;
        a[i]=now++;
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
    return 0;
}