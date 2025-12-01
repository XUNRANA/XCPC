#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
int mi[1000010];
int v[1000010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    mi[n+1]=1e9+2;
    for(int i=n;i>=1;i--) mi[i]=min(mi[i+1],a[i]);
    int mx=a[1];
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,a[i]);
        if(mx<=mi[i+1]) v[i]=1;
    }
    int ans=0;
    for(int k=1;k<=n;k++)
    {
        int f=1;
        for(int j=k;j<=n;j+=k)
        {
            if(v[j]==0)
            {
                f=0;
                break;
            }
        }
        ans+=f;
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