#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int ksm(int a,int b)
{
    b=max(b,0ll);
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
int jc[3010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=3000;i++) jc[i]=jc[i-1]*i%P;
}
int C(int a,int b)
{
    return jc[a]*ksm(jc[a-b]*jc[b]%P,P-2)%P;
}
void solve()
{
    int n=2023;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=i-1;
        int r=n-i;
        int res=ksm(2,l-1)*ksm(2,r-1)%P*C(n-1,l)%P;
        ans=(ans+res)%P;
    }
    cout<<ans<<"\n";
}
signed main()
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
