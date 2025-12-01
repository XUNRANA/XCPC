#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    double c;
    cin>>n>>c;
    double ans=0;
    if(n>=10000000) 
    {
        ans+=2.0;
        n=9999999;
    }
    else if(n>9800000) 
    {
        ans+=1.0+1.0*(n-9800000)/200000;
        n=9800000;
    }
    else ans+=1.0*(n-9500000)/300000;

    ans=max(ans+c,0.0);
    printf("%.7f\n",ans);
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