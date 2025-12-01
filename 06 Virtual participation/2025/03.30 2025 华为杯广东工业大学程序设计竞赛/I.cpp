#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
    int n,m;
    string a,b;
    cin>>n>>m;
    cin>>a>>b;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i+m-1<n)
        {
            if(a.substr(i,m)==b) 
            {
                ans++;
                i=i+m-1;
            }
        }
    }
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