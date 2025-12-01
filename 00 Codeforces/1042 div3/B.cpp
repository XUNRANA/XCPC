#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
void solve()
{
    cin>>n;
    
    for(int i=1;i<=n;i++) if(i&1) a[i]=-1;
    else a[i]=3;

    if(n%2==0) a[n]=2;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    // 2
    // -1 2
    // 3
    // -1 3 -1
    // 4
    // -1 3 -1 2
    // 5
    // -1 3 -1 3 -1 
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}