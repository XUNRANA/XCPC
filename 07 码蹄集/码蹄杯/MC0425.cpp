#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int dp[5010][110];
//dp[i][j] 前i个元素，操作j次的期望
int a[5010][110];
//a[i][j] 前i个元素，操作j次的值
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
int n,m;
int jc[5010];
int inv[5010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=5000;i++) jc[i]=jc[i-1]*i%P;

    inv[5000]=ksm(jc[5000],P-2);
    for(int i=4999;i>=0;i--) inv[i]=inv[i+1]*(i+1)%P;
}
int C(int a,int b)
{
    return jc[a]*inv[b]%P*inv[a-b]%P;
}
int in1[5010][110];
int in2[5010][110];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i][0];
        for(int j=1;j<=m;j++) a[i][j]=a[i][j-1]/2;
    }

    for(int i=1;i<=n;i++)
    {
        int p=ksm(i,P-2);
        int q=(1-p+P)%P;
        in1[i][0]=1;
        in2[i][0]=1;
        for(int j=1;j<=m;j++)
        {
            in1[i][j]=in1[i][j-1]*p%P;
            in2[i][j]=in2[i][j-1]*q%P;
        }
    }
    
    for(int i=0;i<=m;i++) dp[1][i]=a[1][i];

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int t=0;t<=j;t++)
            {
                dp[i][j]=(dp[i][j]+C(j,t)*in1[i][t]%P*in2[i][j-t]%P*((dp[i-1][j-t]+a[i][t])%P)%P)%P;
            }
        }
    }

    cout<<dp[n][m]<<"\n";

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