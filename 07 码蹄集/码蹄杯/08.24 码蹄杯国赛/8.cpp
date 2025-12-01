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
int jc[1000010];
int inv[1000010];

void init()
{
    jc[0]=1;
    for(int i=1;i<=1e6;i++) jc[i]=jc[i-1]*i%P;
    inv[1000000]=ksm(jc[1000000],P-2);
    for(int i=999999;i>=0;i--) inv[i]=inv[i+1]*(i+1)%P;
}


int C(int a,int b)
{
    if(a<b) return 0;
    return jc[a]*inv[b]%P*inv[a-b]%P;
}
int dp[1000010][2];
int sd[1000010][2];
void solve()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int ca=0,cb=0;
    for(auto i:s) if(i=='A') ca++;
    else if(i=='B') cb++;
    
    if(ca+cb<=m)
    {
        cout<<ksm(3,ca)*ksm(2,cb)%P<<"\n";
    }
    else 
    {
        dp[0][0]=1;//a改0个
        for(int i=1;i<=ca;i++)
        {
            dp[i][0]=C(ca,i)*ksm(2,i)%P;
        }

        dp[0][1]=1;//b改0个
        for(int i=1;i<=cb;i++)
        {
            dp[i][1]=C(cb,i);
        }

        sd[0][0]=dp[0][0];//a
        sd[0][1]=dp[0][1];//b
        for(int i=1;i<=1e6;i++) 
        {
            sd[i][0]=(sd[i-1][0]+dp[i][0])%P;
            sd[i][1]=(sd[i-1][1]+dp[i][1])%P;
        }


        int ans=0;
        for(int i=0;i<=ca;i++)
        {
            int j=m-i;
            
            if(j<0) break;
            // cout<<dp[i][0]*sd[j][1]%P<<"??\n";
            ans+=dp[i][0]*sd[j][1]%P;
            ans%=P;
        }
        cout<<ans<<"\n";
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
}