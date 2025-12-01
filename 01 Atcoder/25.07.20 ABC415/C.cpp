#include <bits/stdc++.h>
using namespace std;

int dp[500010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<(1<<n);i++)
    {
        char ch;
        cin>>ch;
        dp[i]=ch-'0';
    }
    
    for(int i=1;i<(1<<n);i++)
    {
        if(dp[i]) continue;
        int f=0;
        for(int j=0;j<n;j++)
        {
            if(i>>j&1)
            {
                if(!dp[i^(1<<j)]) f=1;
            }
        }
        if(f) dp[i]=0;
        else dp[i]=1;
    }

    if(dp[(1<<n)-1]) cout<<"No\n";
    else cout<<"Yes\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

