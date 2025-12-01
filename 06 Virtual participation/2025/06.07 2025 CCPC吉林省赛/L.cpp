#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    if((n&1)&&(m&1)) cout<<ksm(2,n+m-2)<<"\n";
    else if(n&1) cout<<ksm(2,m-1)<<"\n";
    else if(m&1) cout<<ksm(2,n-1)<<"\n";
    else cout<<"1\n";
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