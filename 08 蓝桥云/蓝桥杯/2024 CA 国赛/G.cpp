#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    int l=1,r=n,ans=-1;
    while(l<=r)
    {
        int m=l+r>>1;
        if(m<pow((n+m-1)/m,2)) 
        {
            ans=m;
            l=m+1;
        }
        else r=m-1;
    }
    cout<<min(ans+2,n*n)<<"\n";
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