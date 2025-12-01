#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int a[100010];
int b[100010];
int c[100010];
int cnt[30][3][2];
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        for(int j=0;j<30;j++) if(a[i]>>j&1) cnt[j][0][1]++;
        else cnt[j][0][0]++;
    }
    for(int i=1;i<=n;i++) 
    {
        cin>>b[i];
        for(int j=0;j<30;j++) if(b[i]>>j&1) cnt[j][1][1]++;
        else cnt[j][1][0]++;
    }
    for(int i=1;i<=n;i++) 
    {
        cin>>c[i];
        for(int j=0;j<30;j++) if(c[i]>>j&1) cnt[j][2][1]++;
        else cnt[j][2][0]++;
    }
    
    int ans=0;
    for(int i=1;i<=n;i++) 
    {
        int t=(a[i]+b[i]+c[i])%P;
        ans+=n*n%P*t%P;
        ans%=P;
    }
    // cout<<ans<<"\n";
    for(int i=0;i<30;i++)
    {
        ans-=cnt[i][0][1]*cnt[i][1][1]%P*cnt[i][2][1]%P*3*(1ll<<i)%P;
        ans=(ans+P)%P;
        ans-=cnt[i][0][1]*cnt[i][1][1]%P*(n-cnt[i][2][1])%P*(1ll<<i)%P;
        ans=(ans+P)%P;
        ans-=cnt[i][1][1]*cnt[i][2][1]%P*(n-cnt[i][0][1])%P*(1ll<<i)%P;
        ans=(ans+P)%P;
        ans-=cnt[i][0][1]*cnt[i][2][1]%P*(n-cnt[i][1][1])%P*(1ll<<i)%P;
        ans=(ans+P)%P;
    }
    cout<<ans<<'\n';
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