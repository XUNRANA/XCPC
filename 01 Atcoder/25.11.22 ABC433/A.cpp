#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int x,y,z;
    cin>>x>>y>>z;
    int cnt=1e5;
    while(cnt--)
    {
        if(x%y==0&&x/y==z)
        {
            cout<<"Yes\n";
            return ;
        }
        x++;
        y++;
    }
    cout<<"No\n";

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}