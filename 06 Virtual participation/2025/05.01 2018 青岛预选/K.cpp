#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[30];
void solve() 
{
    int n;
    cin>>n;
    for(int i=0;i<30;i++) c[i]=0;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        c[__lg(x)]++;
    }
    int ans=0;
    for(int i=0;i<30;i++) ans=max(ans,c[i]);
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