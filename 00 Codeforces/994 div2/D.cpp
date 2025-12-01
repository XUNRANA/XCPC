#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N =210;
int a[N][N];
int dp[N][N][N];
int mdp[N][N];
int n,m,k;
int get(int i,int j,int c)
{
    if(j+c<=m) return a[i][j+c];
    else return a[i][j+c-m];
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) mdp[i][j]=1e18;
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) for(int c=0;c<=m;c++) dp[i][j][c]=1e18;
    
    mdp[1][0]=mdp[0][1]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int c=0;c<m;c++)
            {
                dp[i][j][c]=min(dp[i][j][c],mdp[i-1][j]+get(i,j,c)+c*k);//上一层选最小
                dp[i][j][c]=min(dp[i][j][c],dp[i][j-1][c]+get(i,j,c));//这一层固定
                mdp[i][j]=min(mdp[i][j],dp[i][j][c]);
            }
        }
    }

    cout<<mdp[n][m]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
