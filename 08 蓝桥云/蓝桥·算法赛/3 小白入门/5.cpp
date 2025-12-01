#include <bits/stdc++.h>
using namespace std;
long long n,k,a[100010],p[210];
vector<vector<long long>> dp(100010,vector<long long>(210,-1e18));
int main()
{
  cin>>n>>k;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=1;i<=k;i++) cin>>p[i];
  dp[0][0]=0;
  for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i]*p[j];
  cout<<dp[n][k];
}
