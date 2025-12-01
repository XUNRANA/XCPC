#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353




int dp[1<<22];
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    dp[(1<<n)-1]=1;
    for(int i=(1<<n)-1;i>=0;i--) 
    {

        char pre=0;
        for(int j=0;j<n;j++) 
        if(i>>j&1) 
        {
            if(pre!=s[j]) dp[i^(1<<j)]=(dp[i^(1<<j)]+dp[i])%P;
            pre=s[j];
        }    
    }
    cout<<dp[0]<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
