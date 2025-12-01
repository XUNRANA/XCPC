#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[100010];
int c[1000010];
int fx(int x)
{
    int ans=0;
    while(x)
    {
        int i=upper_bound(a+1,a+1+n,x)-a-1;
        int t=x/a[i];
        x-=t*a[i];
        ans+=t;
    }
    return ans;
}
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=a[n];i++) c[fx(i)]++;
    for(int i=1;i<=a[n];i++) c[i]+=c[i-1];
    while(q--)
    {
        int x;
        cin>>x;
        x=min(x,a[n]);
        cout<<c[x]<<" ";
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}