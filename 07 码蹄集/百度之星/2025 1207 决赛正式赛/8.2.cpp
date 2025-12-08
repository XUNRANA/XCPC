#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,x;
int a[200010];
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
    cin>>n>>x;
    int p=x*inv(100)%P;//min
    int q=(100-x)*inv(100)%P;//max
    
    for(int i=1;i<=n;i++) cin>>a[i];

    if(n==1)
    {



        
        cout<<a[1]<<"\n";
        return ;
    }
    int ans=(p*min(a[1],a[2])%P+q*max(a[1],a[2])%P)%P;

    for(int i=3;i<=n;i++)
    {
        cout<<ans<<"??\n";
        ans=(p*min(ans,a[i])%P+q*max(ans,a[i])%P)%P;
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