#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 1000000007
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return  res;
}
void solve()
{
    int n,k,ans;
    cin>>n>>k;
    k=max(k,n-k); 
    if(k==0) ans=ksm(3,n-1)*ksm(4,(n-1)*(n-2)/2)%P;
    else ans=ksm(3,k-1)*ksm(4,n-k)%P*ksm(4,(k-1)*(k-2)/2)%P*ksm(6,(n-k)*(n-k-1)/2)%P*ksm(6,(n-k)*(k-1))%P;
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--) solve();
}
