#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b;
    cin>>a>>b;
    if(abs(a-b)%3!=0) cout<<"No\n";
    else cout<<"Yes\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--) solve();
}