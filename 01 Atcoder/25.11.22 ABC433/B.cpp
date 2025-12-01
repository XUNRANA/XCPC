#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[110];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int f=0;
        for(int j=i-1;j>=1;j--)
        {
            if(a[j]>a[i])
            {
                f=1;
                cout<<j<<"\n";
                break;
            }
        }
        if(!f) cout<<"-1\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}