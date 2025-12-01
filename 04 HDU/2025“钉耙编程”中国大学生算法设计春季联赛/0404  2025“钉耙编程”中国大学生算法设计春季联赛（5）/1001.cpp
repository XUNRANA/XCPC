#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
long long dp[410][410];
void solve()
{
    int n,m,v,x;
    cin>>n>>m>>v;
    for(int i=0;i<=v;i++) for(int j=0;j<=m;j++) dp[i][j]=0;
    dp[0][0]=1;//花费，体积
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(int i1=x;i1<=v;i1++)
        {
            for(int j1=1;j1<=m;j1++)
            {
                dp[i1][j1]+=dp[i1-x][j1-1];
                dp[i1][j1]%=P;
            }
        }
    }
    long long ans=0;
    for(int i=0;i<=v;i++) ans=(ans+dp[i][m])%P;
    cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}