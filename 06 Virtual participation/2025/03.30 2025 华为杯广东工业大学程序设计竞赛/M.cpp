#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int ksm(int a,int b)
{
    if(b<0) return 0;//!!!!!
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
int jc[1000010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=1e6;i++) jc[i]=jc[i-1]*i%P;
}
int C(int a,int b)
{
    if(b>a) return 0;//!!!!!!!
    return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}
void solve() 
{
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        int c=C(k-1,i-1);//分成i段
        if(n-k>=i-1)//大于i-1个间隙
        {
            int res=c*ksm(m,i)%P*ksm(m-1,k-i)%P*C(n-k+1,i)%P;
            ans+=res;
            ans%=P;
            // cout<<i<<" "<<c<<" "<<res<<"\n";
        }
    }
    cout<<ans<<"\n";
}

signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}