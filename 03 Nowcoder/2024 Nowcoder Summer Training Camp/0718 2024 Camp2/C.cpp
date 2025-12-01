#include <bits/stdc++.h>
using namespace std;
int n,ans,cnt1,cnt2,j;
char ch;
int a[2][1000010],dp[2][1000010];
void solve()
{
    ans=0;
    cin>>n;
    for(int i=0;i<2;i++) 
	for(int j=1;j<=n;j++) 
    {
        cin>>ch;
        if(ch=='R') a[i][j]=1;
        else a[i][j]=0;
        dp[i][j]=0;
    }
    
    if(a[0][1]) 
    {
        dp[0][1]++;
        if(a[1][1]) dp[0][1]++;
    }
    
    if(a[1][1])
    {
        dp[1][1]++;
        if(a[0][1]) dp[1][1]++;
    }
    
    ans=max(ans,dp[0][1]-1);
    ans=max(ans,dp[1][1]-1);
    
   
    for(int j=2;j<=n;j++)
    {
        for(int i=0;i<2;i++)
            if(a[i][j])
            {
                dp[i][j]=max(dp[i][j-1]+1,dp[i][j]);
                if(a[i^1][j]) dp[i][j]=max(dp[i^1][j-1]+2,dp[i][j]);
                ans=max(ans,dp[i][j]-1);
            }
    }
    
    cout<<ans<<"\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve(); 
}

