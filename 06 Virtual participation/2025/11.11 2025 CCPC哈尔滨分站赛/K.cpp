#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[5010];
void solve()
{
    int n;
    cin>>n;
    cout<<n<<"\n";
    for(int i=1;i<=n;i++) cout<<i<<" ";
    cout<<"\n";
    a[1]=n;
    a[2]=n+1;
    cout<<a[1]<<" "<<a[2]<<" ";
    for(int i=3;i<=n;i++)
    {
        a[i]=a[i-1]+1+n;
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}