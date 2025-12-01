#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n,m;
    cin>>n>>m;
    if(m>=n)
    {
        cout<<"1\n";
        return ;
    }
    for(int i=1;i<=30;i++)
    {
        int mx=1ll<<(i-1);
        int s=mx*2-1;
        if(s>n||m-i<=0) continue;
        int a1=(n-s)/(m-i);
        int a2=(n-s+m-i-1)/(m-i);
        if(a1>=mx&&a1<=s+1)
        {
            // cout<<a1<<" "<<a2<<" "<<i<<"\n";  
            cout<<a2<<"\n";
            return ;
        }
    }
    cout<<"-1\n";
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