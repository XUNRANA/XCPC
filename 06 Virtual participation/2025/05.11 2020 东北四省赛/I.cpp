#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010][1010];
void solve() 
{
    int n;
    while(cin>>n)
    {
        int ans=0;
        int mi=1e6;
        for(int i=1;i<=n;i++) 
        {
            for(int j=1;j<=n;j++)
            {
                cin>>a[i][j];
                if(i!=j) mi=min(mi,a[i][j]);
            }
        }
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans+=(mi==a[i][j]);
        cout<<ans<<"\n";
    }
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