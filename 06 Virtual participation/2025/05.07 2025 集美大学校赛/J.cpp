#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
void solve() 
{
    cin>>n;
    cout<<4+(n-4)*2<<"\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}