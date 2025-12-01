#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,p,ans,s;
int dp[5000][5000],a[5000],res[5000];
void pre()
{
	res[0]=1;
    res[1]=2;
    for(int i=2;i<=n;i++) res[i]=res[i-1]*2%p;
}
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%p;
        a=a*a%p;
        b/=2;
    }
    return res;
}
signed main()
{
    cin>>n>>k>>p;
    pre();
    for(int i=1;i<=n;i++) cin>>a[i],s=(s+a[i]/k)%p,a[i]%=k;
    ans=s*res[n-1];
    dp[1][a[1]]=1; 
    for(int i=2;i<=n;i++)
    {
        dp[i][a[i]]++;
        for(int j=0;j<k;j++)
        {
            if(dp[i-1][j])
            {
                dp[i][j]+=dp[i-1][j];
                if(j+a[i]>=k)
                {
                    dp[i][(j+a[i])%k]=(dp[i][(j+a[i])%k]+dp[i-1][j])%p;
                    ans=(ans+res[n-i]*dp[i-1][j]%p+p)%p; 
                }
                else dp[i][a[i]+j]=(dp[i][a[i]+j]+dp[i-1][j])%p;    
            }
        }
    }
    cout<<ans<<"\n";
}
