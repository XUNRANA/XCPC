#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    int mx=0;
    while(n--)
    {
        int m;
        cin>>m;
        vector<int>a;
        while(m--)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        cin>>m;
        int s=0;
        for(int i=0;i<m;i++) s+=a[i];
        mx=max(mx,s);
    }
    cout<<mx<<"\n";
    
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}