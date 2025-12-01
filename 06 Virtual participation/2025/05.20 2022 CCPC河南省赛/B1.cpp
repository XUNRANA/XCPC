#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
ll dp[200010];
int g(char ch)
{
    if(ch=='a') return 1;
    else if(ch=='e') return 2;
    else if(ch=='h') return 3;
    else return 4;
}
string s;
ll fx(int l,int r)
{
    ll sum=0;
    for(int i=l;i<=r;i++) sum=(sum*31l%P+g(s[i]))%P;
    return sum;
}
ll get(int n)
{
    for(int i=0;i<=n;i++) dp[i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=max(1,i-15);j<=i;j++)
        {
            dp[i]=max(dp[i],dp[j-1]+fx(j,i));
        }
    }
    return dp[n];
}
void solve()
{
    string t;
    cin>>t;
    int n=t.size();
    t=" "+t+t;
    ll ans=0;
    for(int i=1;i<=min(n,15);i++)
    {
        s=t.substr(i,n);
        s=" "+s;
        cout<<get(n)<<"\n";
        ans=max(ans,get(n));
    }
    cout<<ans<<"\n";
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
