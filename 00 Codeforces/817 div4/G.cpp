#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
bool ck()
{
    int x1=0,x2=0;
    for(int i=1;i<=n;i++) if(i&1) x1^=a[i];
    else x2^=a[i];
    return x1==x2;
}
void solve() 
{
    cin>>n;

    if(n%4==0)
    {
        for(int i=1;i<=n-1;i++) a[i]=i-1;
        int o=0;
        int e=0;
        for(int i=1;i<=n-1;i++) 
        if(i&1) o^=a[i];
        else e^=a[i];
        a[n]=o^e;
        for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];

    }   
    else 
    {
        for(int i=1;i<=n-1;i++) a[i]=i;
        int o=0;
        int e=0;
        for(int i=1;i<=n-1;i++) 
        if(i&1) o^=a[i];
        else e^=a[i];
        a[n]=o^e;
        a[1]|=1ll<<30;
        if(n&1) a[n]|=1ll<<30;
        else a[n-1]|=1ll<<30;
        for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    }
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