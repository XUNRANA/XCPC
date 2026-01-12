#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int s,k,m;
    cin>>s>>k>>m;
    //s分钟的沙漏
    //每k分钟翻转一次
    //m分钟后 还得漏多少分钟沙漏露完
    if(s<=k) cout<<max(0ll,s-m%k)<<"\n";
    else
    {
        m%=(2*k);
        if(m<k) cout<<s-m<<"\n";
        else cout<<k-(m-k)<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}