#include <bits/stdc++.h>
using namespace std;
string s;
int ans=1,dp[200010][2];
void solve()
{
    cin>>s;
    dp[0][0]=0+(s[0]=='0'||s[0]=='?');
    dp[0][1]=0+(s[0]=='1'||s[0]=='?');
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='0') 
        {
            dp[i][0]=dp[i-1][0]+1;
            dp[i][1]=0;
        }
        else if(s[i]=='1')
        {
            dp[i][1]=dp[i-1][1]+1;
            dp[i][0]=0;
        }
        else 
        {
            dp[i][1]=dp[i-1][1]+1;
            dp[i][0]=dp[i-1][0]+1;
        }
        
        ans=max({ans,dp[i][0],dp[i][1]});
       // cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

