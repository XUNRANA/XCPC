#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int jc[5000010];
int inv[5000010];
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
int inv1(int x)
{
    return ksm(x,P-2);
}
void init()
{
    jc[0]=1;
    for(int i=1;i<=5e6;i++) jc[i]=jc[i-1]*i%P;
    inv[5000000]=ksm(jc[5000000],P-2);
    for(int i=5e6-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%P;
}
int C(int a,int b)
{
    return jc[a]*inv[b]%P*inv[a-b]%P;
}
int n,r,a,h,R1,R2;
void solve()
{
    cin>>n>>R1>>R2>>r>>a>>h;
    if(R1+r>=R2) cout<<"1\n";
    else
    {
        int p=(R1+r)*(R1+r)%P;
        p=p*inv1(R2*R2%P)%P;
        int c=(h+a-1)/a;     
        int s=0;
        for(int i=c;i<=n;i++) 
        {
            s+=C(n,i)*ksm(p,i)%P*ksm((1-p+P)%P,n-i)%P;
            s%=P;
        }
        cout<<s<<"\n";
    }
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
