#include <bits/stdc++.h>
using namespace std;

void solve () 
{
    int n;
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++) s+=abs((n-i+1)-i);
    cout<<s/2+1<<"\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}