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
int inv(int x)
{
    return ksm(x,P-2);
}
vector<array<int,3>>g[200010];
int dp[200010];
void solve()
{
    int n,m,l,r,p,q;
    cin>>n>>m;
    int res=1;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r>>p>>q;
        
        p=p*inv(q)%P;
        q=(1-p+P)%P;
        g[l].push_back({r,p,q});

        res=res*q%P;
    }



    dp[0]=res;
    for(int i=1;i<=m;i++)
    {
        for(auto r:g[i])
        {
            dp[r[0]]+=dp[i-1]*r[1]%P*inv(r[2])%P;
            dp[r[0]]%=P;
        }
    }

    cout<<dp[m]<<"\n";
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}