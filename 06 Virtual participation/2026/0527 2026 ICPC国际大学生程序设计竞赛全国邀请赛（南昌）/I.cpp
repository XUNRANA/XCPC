#include <bits/stdc++.h>
using namespace std;
#define int long long
int d,l;
int t0,t1,t2;
int dp[200010][4];
int t[3];
// 0 1 2 3
void solve()
{
    cin>>l>>d;
    cin>>t[0]>>t[1]>>t[2];
    string s;
    cin>>s;
    s=" "+s;

    for(int i=0;i<=l;i++) dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=1e18;
    dp[0][0]=0;
    dp[1][0]=dp[0][0]+t[s[1]-'0'];
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<4;j++)
        {
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+t[s[i+1]-'0']);
            if(j<3) dp[min(l,i+d)][j+1]=min(dp[min(i+d,l)][j+1],dp[i][j]);
        }
    }
    cout<<min({dp[l][0],dp[l][1],dp[l][2],dp[l][3]})<<"\n";



}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
