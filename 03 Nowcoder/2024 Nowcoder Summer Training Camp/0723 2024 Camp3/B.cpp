#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,g,a[110];
signed main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    g=a[1];
    for(int i=2;i<=n;i++) g=gcd(g,a[i]);
    cout<<min(d%g,g-d%g);
}