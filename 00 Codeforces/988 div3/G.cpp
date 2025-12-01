#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int f[1000010];
int dp[1000010];
int dp1[1000010];
vector<int>g[1000010];
void init()
{
    for(int i=2;i<=1e6;i++)
    {
        if(!f[i])
        for(int j=i;j<=1e6;j+=i)
        {
            g[j].push_back(i);
            f[j]=1;
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    dp[1]=1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        int c=g[x].size();
        for(int j=1;j<1<<c;j++)
        {
            int v=1,cnt=0;
            for(int k=0;k<c;k++)
            if(j>>k&1) v*=g[x][k],cnt++;
            if(cnt&1) dp[i]=(dp[i]+dp1[v])%P;
            else dp[i]=(dp[i]-dp1[v]+P)%P;
        }
        for(int j=1;j<1<<c;j++)
        {
            int v=1;
            for(int k=0;k<c;k++)
            if(j>>k&1) v*=g[x][k];
            dp1[v]=(dp1[v]+dp[i])%P;
        }
    }
    cout<<dp[n]<<"\n";
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
