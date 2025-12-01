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
int inv(int x)
{
    return ksm(x,P-2);
}
void solve()
{
    int n;
    cin>>n;
    int ans=((n%P)*(n%P)%P-(n%P)*((n-1)%P)%P*inv(2)%P+P)%P;
    for(int b=1;b<=n;)
    {
        int l=n/b;
        int r=n/l;
        ans=(ans-(r-b+1)%P*(n/b)%P+P)%P;
        b=r+1;
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
}