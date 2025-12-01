#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200010];
void solve()
{
    cin>>n>>m;
    unordered_map<int,int>mp[12];//1-11
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
        for(int j=1;j<=11;j++)
        {
            x=x*10;
            x%=m;
            mp[j][x]++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        
        int len=to_string(a[i]).size();
        int x=a[i]%m;
        if(x==0) ans+=mp[len][0];
        else ans+=mp[len][m-x];
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}