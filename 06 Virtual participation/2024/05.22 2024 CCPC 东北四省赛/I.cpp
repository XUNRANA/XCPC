#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int jc[100010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=1e5;i++) jc[i]=jc[i-1]*i%P;
}
int dp[100010];
int g[1010];
void solve()
{
    int n,k;
    cin>>n>>k;
    if(k>n) cout<<"0\n";
    else if(k==n) cout<<jc[k]<<"\n";
    else 
    {
        for(int i=1;i<=k;i++)
        {
            g[i]=jc[i];
            for(int j=1;j<i;j++) g[i]=(g[i]-(jc[j]*g[i-j])%P+P)%P;
        }

        dp[k]=jc[k];
        for(int i=k+1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                dp[i]+=dp[i-j]*g[j]%P;
                dp[i]%=P;
            }
        }
        cout<<dp[n]<<"\n";
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
