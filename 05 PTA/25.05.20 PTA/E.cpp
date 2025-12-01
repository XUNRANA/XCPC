#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int x;
    cin>>x;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n+2,vector<int>(m+2,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    set<pair<int,int>>st;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]&&j+1<=m&&a[i][j+1])
            {
                st.insert({min(a[i][j],a[i][j+1]),max(a[i][j],a[i][j+1])});
            }
            if(a[i][j]&&i+1<=n&&a[i+1][j])
            {
                st.insert({min(a[i][j],a[i+1][j]),max(a[i][j],a[i+1][j])});
            }
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        if(st.count({x,y})) cout<<"yes\n";
        else cout<<"no\n";
    }
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