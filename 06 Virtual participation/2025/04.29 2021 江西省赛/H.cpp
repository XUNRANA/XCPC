#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
void solve() 
{
    cin>>n>>k;
    if(n==1) cout<<"freesin\n";
    else if(k+1>=n) cout<<"pllj\n";
    else cout<<"freesin\n";
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
