#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[200010][2];
void solve()
{
	string s;
	cin>>s;
    for(int i=0;i<s.size();i++) dp[i][0]=dp[i][1]=1e9;
    dp[0][0]=0;
    dp[0][1]=1;
    for(int i=1;i<s.size();i++)
    {
        if(isupper(s[i])) 
        {
            dp[i][0]=dp[i-1][1];
            dp[i][1]=min(dp[i-1][1],dp[i-1][0])+1;
        }
        else
        {
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
        }
    }
    cout<<min(dp[s.size()-1][0],dp[s.size()-1][1])<<"\n";
//     for(int i=0;i<s.size();i++)
//     cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}


