#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,m;
vector<int>a[100010];
vector<pair<int,int>>idx[100010];
int jc[100010];
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
int C(int a,int b)
{
    return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}
void init()
{
    jc[0]=1;
    for(int i=1;i<=100000;i++) jc[i]=jc[i-1]*i%P;
}
int fx(int x)
{
    //1 出现过x
    //0 未出现
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(2,0)));
    if(a[1][1]==x) dp[1][1][1]=1;
    else dp[1][1][0]=1;
    int ans=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
    {
        if(i==1&&j==1) continue;
        if(a[i][j]==x) 
        {
            dp[i][j][1]+=dp[i-1][j][0]+dp[i][j-1][0]+dp[i-1][j][1]+dp[i][j-1][1];
            dp[i][j][1]%=P;
        }
        else 
        {
            dp[i][j][1]+=dp[i-1][j][1]+dp[i][j-1][1];
            dp[i][j][0]+=dp[i-1][j][0]+dp[i][j-1][0];
            dp[i][j][1]%=P;
            dp[i][j][0]%=P;
        }
    }
    return dp[n][m][1];
}
int fx1(int x)
{
    vector<int>dp(idx[x].size(),0);
    int res=0;
    for(int i=0;i<idx[x].size();i++)
    {
        int x1=idx[x][i].first;
        int y1=idx[x][i].second;
        dp[i]=C(x1-1+y1-1,x1-1);
        for(int j=0;j<i;j++)
        {
            int x2=idx[x][j].first;
            int y2=idx[x][j].second;
            if(x2<=x1&&y2<=y1)
            {        
                dp[i]-=dp[j]*C(x1-x2+y1-y2,x1-x2)%P;
                dp[i]=(dp[i]+P)%P;
            }
        }
        res+=dp[i]*C(n-x1+m-y1,n-x1)%P;
        res%=P;
    }
    return res;
}
void solve() 
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) a[i].resize(m+1,0);
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            idx[a[i][j]].push_back({i,j});
        }
    }
    int lim=sqrt(n*m);
    int ans=0;
    for(int i=1;i<=n*m;i++) 
    if(idx[i].size()>=lim) 
    {
        ans+=fx(i);
        ans%=P;
    }
    else if(idx[i].size())
    {
        ans+=fx1(i);
        ans%=P;
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n*m;i++) 
    {
        if(i<=n) a[i].clear();
        idx[i].clear();
    }
}

signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
