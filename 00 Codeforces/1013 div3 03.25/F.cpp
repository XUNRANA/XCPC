#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,m,d;
int a[2010][2010];
int dp[2010][2010][2];
int pre[2010];
void print()
{
    for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<dp[i][j][0]<<" ";
    for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<dp[i][j][1]<<" ";
}
void solve()
{
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++) 
    for(int j=1;j<=m;j++) 
    {
        dp[i][j][0]=dp[i][j][1]=0;
        char ch;
        cin>>ch;
        if(ch=='X') a[i][j]=1;
        else a[i][j]=0;
    }
    for(int i=n;i>=1;i--)
    {
        if(i==n) for(int j=1;j<=m;j++) dp[i][j][0]=a[i][j];

        for(int j=1;j<=m;j++) pre[j]=(pre[j-1]+dp[i][j][0])%P;

        for(int j=1;j<=m;j++)
        {
            if(a[i][j])
            {
                int r=min(j+d,m);
                int l=max(j-d,1ll);
                dp[i][j][1]=(pre[r]-pre[l-1]-dp[i][j][0]+P)%P;
            }
        }

        for(int j=1;j<=m;j++) pre[j]=(pre[j-1]+dp[i][j][0]+dp[i][j][1])%P;

        for(int j=1;j<=m;j++)
        {
            if(i-1>=1&&a[i-1][j])
            {
                int l=max(1ll,j-(d-1));
                int r=min(m,j+(d-1));
                dp[i-1][j][0]+=(pre[r]-pre[l-1]+P)%P;
                dp[i-1][j][0]%=P;
            }
        }
        // cout<<i<<" "<<"???\n";
        // print();
    }
    

    int ans=0;
    for(int j=1;j<=m;j++) 
    if(a[1][j]) ans=((dp[1][j][0]+dp[1][j][1])%P+ans)%P;
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
