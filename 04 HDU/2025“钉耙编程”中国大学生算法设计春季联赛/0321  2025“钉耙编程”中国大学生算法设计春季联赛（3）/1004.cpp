#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
struct node
{
    int x,i;
}a[300010];
bool cmp(node a1,node a2)
{
    return a1.x<a2.x;
}
int f[300010];
int dp[300010][2];
void solve()
{
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].x,a[i].i=i,f[i]=0;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=m;i++) cin>>x,f[x]=1;
    for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=1e18;


    dp[0][0]=0;
    dp[0][1]=1e18;
    dp[1][0]=0;
    dp[1][1]=1e18;
    for(int i=2;i<=n;i++)
    if(f[a[i-1].i])
    {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=min(dp[i][1],(a[i].x-a[i-1].x)*(a[i].x-a[i-1].x)+dp[i-1][0]);
    }
    else
    {
        dp[i][1]=min(dp[i][1],min(dp[i-1][0]+(a[i].x-a[i-1].x)*(a[i].x-a[i-1].x),dp[i-2][0]+(a[i].x-a[i-2].x)*(a[i].x-a[i-2].x)));
        dp[i][0]=min(dp[i][0],min(dp[i-1][0],dp[i-1][1]));
    }


    if(f[a[n].i]) cout<<dp[n][1]<<"\n";
    else cout<<min(dp[n][0],dp[n][1])<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
