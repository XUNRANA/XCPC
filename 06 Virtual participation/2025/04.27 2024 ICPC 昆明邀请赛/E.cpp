#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[300010];
int p[300010];
int s[300010];
void solve() 
{
    int n,x;
    cin>>n>>x; 
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) p[i]=__gcd(p[i-1],a[i]);
    int ans=p[n];
    s[n+1]=0;
    for(int i=n;i>=1;i--) s[i]=__gcd(s[i+1],a[i]);

    for(int i=1;i<=n;i++) 
    if(p[i]!=p[i-1])
    {
        int g=0;
        for(int j=i;j<=n;j++)
        {
            g=__gcd(g,a[j]+x);
            ans=max(ans,__gcd(__gcd(p[i-1],s[j+1]),g));
        }
    }
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}