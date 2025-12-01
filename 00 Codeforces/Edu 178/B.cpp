#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010];
int b[200010];
int c[200010];
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[i]=max(b[i-1],a[i]);
    c[n+1]=1e9;
    int s=0;
    for(int i=n;i>=1;i--)
    {
        s+=a[i];
        cout<<max(s-a[i]+b[i-1],s)<<" \n"[i==1];
    }
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}