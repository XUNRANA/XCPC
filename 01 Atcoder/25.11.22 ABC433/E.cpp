#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
void solve()
{
    cin>>n>>m;
    vector<int>a(n+1,0);
    vector<int>b(m+1,0);
    vector<vector<int>>ans(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

    for(int x=n*m;x>=1;x--)
    {
        
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