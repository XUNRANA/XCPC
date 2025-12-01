#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n,m;
    cin>>n>>m;
    int s=0;
    int ans=0;
    while(n--)
    {
        int x;
        cin>>x;
        
        if(s+x>m) 
        {
            ans++;
            s=x;
        } 
        else s+=x;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
