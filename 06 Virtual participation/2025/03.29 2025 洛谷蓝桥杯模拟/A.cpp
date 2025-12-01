#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353

int is(int y)
{
    if(y%100==0) return y%400==0;
    return y%4==0;
}
int m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void solve() 
{
    // 20250329
    // 21151231
    int ans=0;
    for(int i=2025;i<=2115;i++)
    {
        if(i==2025)
        {
            ans=3;
            for(int j=4;j<=12;j++) ans+=m[j];
        }
        else for(int j=1;j<=12;j++)
        {
            ans+=m[j];
            if(j==2&&is(i)) ans++;
        }
    }
    cout<<ans<<"\n";
    // cout<<46*46<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}