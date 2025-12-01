#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,a[300010];
int b[300010];
int c[2];
int s[2];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        a[i]^=a[i-1];
    }
    int ans=0;
    for(int i=0;i<=30;i++)
    {
        for(int j=1;j<=n;j++) b[j]=a[j]>>i&1;
        c[0]=c[1]=0;
        s[0]=s[1]=0;
        for(int j=0;j<=n;j++)
        {
            c[b[j]]++;
            s[b[j]]+=j;
            s[b[j]]%=P;
            ans+=(c[b[j]^1]*j%P-s[b[j]^1]+P)%P*(1<<i)%P;
            ans%=P;
        }
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
}