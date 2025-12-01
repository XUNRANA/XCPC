#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[13];
int b[52];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int c,t;
        cin>>c>>t;
        b[i]=t;
        if(b[a[c]]<t) a[c]=i;
    }
    for(int i=1;i<=m;i++) cout<<a[i]<<" ";
    cout<<"\n";
    
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
