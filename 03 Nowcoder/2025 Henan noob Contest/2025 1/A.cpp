#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int jc[5010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=5000;i++) jc[i]=jc[i-1]*i%P;
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
    int n,m;
    cin>>n>>m;
    if(n<m) cout<<"0\n";
    else if(n==m) cout<<jc[n]<<"\n";
    else 
    {
        int ans=0;
        int f=1;
        for(int i=m;i>=1;i--) 
        {
            // cout<<f*ksm(i,n)<<"\n";
            ans=(ans+C(m,i)*f*ksm(i,n)%P+P)%P;
            f*=-1;
        } 
        cout<<ans<<"\n";
        //n个球分成m份、不能为空
        // 1 1 1 
        // cout<<C(n,m)*ksm(m,n-m)%P<<"\n";
    }




    //n 2
    // 2^n -2
    // 4 3
    // 3^4=81-16*3-3
    // 81-48+3=33+3=36
    // 1 1 1  
    // 1 1 1 
    // 1 1 1
    // 1 1 1
    // 4 2
    // 1 3  4 
    // 2 2  6
    // 3 1  4

   //3 3
    // 1 1 1   6
    // //4 3 
    // 1 1 2  4*3 12 *3=36
    // 1 2 1  4*3
    // 2 1 1  6*2

    // //5 3   150
    // 1 1 3   20
    // 1 3 1   20
    // 3 1 1   20

    // 1 2 2   30
    // 2 1 2   30
    // 2 2 1   30
}

signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}