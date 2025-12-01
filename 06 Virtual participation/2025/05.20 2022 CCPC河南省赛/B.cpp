#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
#define P1 31
int p[400010];
int h[400010];
int dp[400010];
int n;
int g(char ch)
{
    if(ch=='a') return 1;
    else if(ch=='e') return 2;
    else if(ch=='h') return 3;
    else return 4;
}

int get(int l,int r)
{
    return (h[r]-h[l-1]*p[r-l+1]%P+P)%P;
}

int fx(int a)
{
    for(int i=0;i<=n;i++) dp[i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=max(1ll,i-20);j<=i;j++)
        {
            dp[i]=max(dp[i],dp[j-1]+get(j+a,i+a));
        }
    }
    return dp[n];
}
void solve()
{
    string s;
    cin>>s;
    n=s.size();
    s=" "+s+s;
    p[0]=h[0]=1;
    for(int i=1;i<=2*n;i++)
    {
        p[i]=p[i-1]*P1%P;
        h[i]=(h[i-1]*P1%P+g(s[i]))%P;
    }
    int ans=0;
    for(int i=0;i<=min(n,20ll);i++) 
    {
        ans=max(ans,fx(i));
    }
    cout<<ans<<"\n";
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
