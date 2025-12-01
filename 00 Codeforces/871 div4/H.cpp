#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int p2[200010];
void init()
{
    p2[0]=1;
    for(int i=1;i<=200000;i++) p2[i]=p2[i-1]*2%P;
}
int n,k,x;
int dp[64];
void solve()
{
    cin>>n>>k;
    for(int i=0;i<64;i++) dp[i]=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        for(int j=0;j<64;j++) if((x&j)==j) dp[j]++;
    }
    for(int i=63;i>=0;i--) 
    {
        dp[i]=(p2[dp[i]]-1+P)%P;
        for(int j=i+1;j<=63;j++) if((j&i)==i) dp[i]=(dp[i]-dp[j]+P)%P;
    }
    int ans=0;
    for(int i=0;i<64;i++) if(__builtin_popcount(i)==k) ans=(ans+dp[i])%P;
    cout<<ans<<"\n";
}
signed main()
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
