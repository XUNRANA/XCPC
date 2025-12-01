#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1000010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        mp[a[i]]++;
        int l=(*mp.begin()).first;
        int cl=(*mp.begin()).second;

        int r=(*mp.rbegin()).first;
        int cr=(*mp.rbegin()).second;
        if(cr>=i-1) cout<<r+r<<" ";
        else cout<<l+r<<" ";
    }
    cout<<"\n";
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}