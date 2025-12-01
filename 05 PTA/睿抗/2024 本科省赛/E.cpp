#include <bits/stdc++.h>
using namespace std;
int n;
int dp[5010];
struct node
{
    int t,d,p;
}a[5010];
bool cmp(node a1,node a2)
{
    return a1.d<a2.d;
    // return a1.d-a1.t<a2.d-a2.t;
}
void solve()
{
    cin>>n;
    for(int i=0;i<=5000;i++) dp[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i].t>>a[i].d>>a[i].p;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        int s=a[i].d-a[i].t;
        for(int j=s;j>=0;j--) dp[j+a[i].t]=max(dp[j+a[i].t],dp[j]+a[i].p);
        // for(int j=1;j<=5000;j++) dp[j]=max(dp[j],dp[j-1]);
    }
    int ans=0;
    for(int j=0;j<=5000;j++) ans=max(ans,dp[j]);
    cout<<ans<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
