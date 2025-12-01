#include <bits/stdc++.h>
using namespace std;
#define int long long

// 0 0 0 1 2 3      0 4 8 
// 1:1 1 1 2 3 0    1 5
// 2:2 2 2 3 0 1    2 6 
// 3:3 3 3 0 1 2    3 7

// 3 3 3 0 1 3

// 1 1 1 2 1 1

// 2 2 2 2 2 2 

int s[5];
int n,a[1000010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=1e9;
    for(int j=0;j<4;j++)
    {
        s[j]=0;
        for(int i=1;i<=n;i++) 
        {
            if(a[i]>=j) s[j]+=a[i]-j;
            else s[j]+=a[i]+4-j;
        }
        int x=(j+s[j])%4;
        if(!x) 
        {
            // cout<<j<<" "<<s[j]<<"\n";
            ans=min(ans,s[j]);
        }
        else 
        {
            // cout<<j<<" "<<s[j]+4-x<<"\n";
            ans=min(ans,s[j]+4-x);
        }
    }
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
