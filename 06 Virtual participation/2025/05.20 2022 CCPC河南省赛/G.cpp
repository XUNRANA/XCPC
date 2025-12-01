#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1010][4010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            a[i][j]=ch-'0';
            if(i!=1) a[i][j]&=a[i-1][j];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int i,j,l,r,p;
        cin>>i>>j>>l>>r>>p;
    }
    int ans=0;
    for(int i=1;i<=m;i++) ans+=(a[n][i]==1);
    cout<<ans<<"\n";

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
