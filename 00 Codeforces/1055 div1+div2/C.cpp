#include <bits/stdc++.h>
using namespace std;
#define int long long


int n,q;
int l,r;
int a[250010];
int b[250010];
int s[250010];
int sb[250010];


void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<n;i++) 
    {
        b[i]=(a[i]==a[i+1]);
        sb[i]=sb[i-1]+b[i];
    }
    while(q--)
    {
        cin>>l>>r;
        if((r-l+1)%3!=0||(s[r]-s[l-1])%3!=0) cout<<"-1\n";
        else 
        {
            if(sb[r-1]-sb[l-1]) cout<<(r-l+1)/3<<"\n";
            else cout<<(r-l+1)/3+1<<"\n";
        }
    }
    // 0 1 0 1 0 1 0 1 0 1 0 1
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}