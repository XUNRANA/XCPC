#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() 
{
    int k;
    cin>>k;
    int x=1,y=1;
    cout<<2*k-1<<"\n";
    for(int i=1;i<=2*k-1;i++) 
    {
        cout<<x<<" "<<y<<"\n";
        x++;
        y++;
    }
}

int32_t main() 
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}