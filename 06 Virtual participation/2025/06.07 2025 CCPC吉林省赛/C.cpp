#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353


int n,k;
int a[11];
int s[11];
int p[11];
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
void solve()
{
    cin>>n>>k;
    s[0]=0;
    p[0]=1;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        s[i]=(s[i-1]+a[i])%P;
        p[i]=(p[i-1]*a[i])%P;
    }
    string t;
    cin>>t;
    reverse(t.begin(),t.end());
    int ans;

    if(t[0]=='s') ans=s[n];
    else ans=p[n];

    
    for(int i=1;i<k;i++)
    {
        if(t[i]=='s')
        {
            ans=ans*n%P;
        }
        else 
        {
            ans=ksm(ans,n);
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
    return 0;
}