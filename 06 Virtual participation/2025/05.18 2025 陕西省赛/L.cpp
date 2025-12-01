#include <bits/stdc++.h>
using namespace std;
#define int long long

// 1 2
// 3 4

//1 2 3
//4 5 6
//7 8 
int a[1010][1010];
void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=(i-1)*n+j;
            if(i==j) ans+=a[i][j];
            if(i==j-1) ans+=a[i][j];
        }
    }
    ans+=a[n][1];
    cout<<ans<<"\n";
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