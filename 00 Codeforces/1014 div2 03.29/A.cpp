#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,x;
    cin>>n;
    int mx=2;
    int mi=1e9;
    for(int i=1;i<=n;i++) 
    {
        cin>>x;
        mx=max(mx,x);
        mi=min(mi,x);
    }
    cout<<mx-mi<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
