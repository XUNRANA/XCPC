#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[500010];
int p[500010];
int s[500010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        s[i]=p[i]=-1e9;
    }
    
    int mx1=-1e9;
    int s1=0;
    for(int i=1;i<=n;i++)
    {
        s1+=a[i];
        mx1=max(mx1,s1);
        s1=max(s1,0ll);
        p[i]=mx1;
    }


    mx1=-1e9;
    s1=0;
    for(int i=n;i>=1;i--)
    {
        s1+=a[i];
        mx1=max(mx1,s1);
        s1=max(s1,0ll);
        s[i]=mx1;
    }
    
    for(int i=2;i<=n;i++) p[i]=max(p[i],p[i-1]);
    
    for(int i=n-1;i>=1;i--) s[i]=max(s[i],s[i+1]);

    // for(int i=1;i<=n;i++) cout<<p[i]<<" \n"[i==n];
    // for(int i=1;i<=n;i++) cout<<s[i]<<" \n"[i==n];

    int ans=-2e9;

    for(int i=1;i<n;i++) ans=max(ans,p[i]+s[i+1]);
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