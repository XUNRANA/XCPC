#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,k;
    cin>>n>>k;
    if(k==0)
    {
        for(int i=1;i<=n;i++) cout<<"2";
        cout<<"\n";
    }
    else if(k==n)
    {
        for(int i=1;i<=n;i++) cout<<"1";
        cout<<"\n";
    }
    else
    {   
        for(int i=1;i<=k;i++) cout<<"1";
        for(int i=k+1;i<=n;i++) cout<<"4";
        cout<<"\n";
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
