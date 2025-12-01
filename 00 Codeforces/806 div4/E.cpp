#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[110][110];
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char ch;
            cin>>ch;
            a[i][j]=(ch=='1');
        }
    }

    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n-i;j++)
        {
            // cout<<i<<" "<<j<<"?\n";
            int x=i;
            int y=j;
            int ans=0;
            ans+=a[x][y];
            ans+=a[y][n-x+1];
            ans+=a[n-x+1][n-y+1];
            ans+=a[n-y+1][x];
            // cout<<x<<" "<<y<<"\n";
            // cout<<y<<" "<<n-x+1<<"\n";
            // cout<<n-x+1<<" "<<n-y+1<<"\n";
            // cout<<n-y+1<<" "<<x<<"\n";
            res+=min(ans,4-ans);
            // cout<<min(ans,4-ans)<<"\n";
        }
    }
    cout<<res<<"\n";
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