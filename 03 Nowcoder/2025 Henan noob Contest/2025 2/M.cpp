#include <bits/stdc++.h>
using namespace std;
#define int long long

double pi=3.1415926535;
void solve()
{
    int n;
    cin>>n;
    printf("%.2f\n",pow(1.0*n/2,2)*pi/2);
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

