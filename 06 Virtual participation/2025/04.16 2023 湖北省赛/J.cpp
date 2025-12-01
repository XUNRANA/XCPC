#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[100010];
int a[100010];
int n;
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],p[i]=p[i-1]+a[i];
    if(p[n]<0)
    {
        cout<<"-1\n";
        return ;
    }
    for(int i=1;i<=n;i++) 
    if(a[i]!=0)
    {
        if(a[i]<0)
        {
            cout<<"-1\n";
            return ;
        }
        break;
    }

    
    int now=0;
    int t=n;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,p[i-1]);
        now+=p[i];
        if(now<0)
        {
            int cnt=((0-now)+mx-1)/mx;
            t+=cnt;
            now+=mx*cnt;
        }
    }
    cout<<t<<"\n";
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