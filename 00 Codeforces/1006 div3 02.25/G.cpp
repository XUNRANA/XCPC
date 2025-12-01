#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,k;
int rev(int x,int p)
{
    int res=0;
    while(x)
    {
        res=(res*p%P+x%p)%P;
        x/=p;
    }
    return res;
}
int sum(int l,int r)
{
    return r-l+1;
}
int sum_pow(int x)
{
    return (x*(x+1)*(2*x+1)/6)%P;
}
int fx(int l,int r)
{
    if(l>r) return 0;
    int res=n*(l+r)*(r-l+1)/2;
    while(l<=k)
    {
        int t=n/l;
        r=min(n/t,k);
        res=(res+t*((sum(l,r)-sum_pow(r)+sum_pow(l-1)+2*P)%P)%P)%P;
        l=r+1;
    }
    return res;
}
void solve()
{
    cin>>n>>k;
    int ans=0;
    if(k>n) 
    {
        ans+=(k-n)%P*n%P;
        ans%=P;
        k=n;
    }
    for(int i=2;i*i<=n&&i<=k;i++)
    {
        ans+=rev(n,i);
        ans%=P;
    }
    ans+=fx(sqrt(n)+1,k);
    ans%=P;
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
