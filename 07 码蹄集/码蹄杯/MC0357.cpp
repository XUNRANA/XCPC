#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int sx,sy,tx,ty,n,p,q;
int jc[300010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=3e5;i++) jc[i]=jc[i-1]*i%P;
}
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
int C(int a,int b)
{
    return jc[a]*inv(jc[b]*jc[a-b]%P)%P;
}
void solve()
{
    cin>>sx>>sy>>tx>>ty>>n>>p>>q;
    int dx=tx-sx;
    int dy=ty-sy;
    if(dx<0||dy<0||dx+dy!=n) cout<<"0\n";
    else
    {
        int p1=p*inv(100)%P;
        int p2=q*inv(100)%P;
        // cout<<C(n,dx)<<" "<<p1<<" "<<p2<<"?\n";
        int ans=C(n,dx)*ksm(p1,dx)%P*ksm(p2,dy)%P;
        cout<<ans<<"\n";
    }
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
