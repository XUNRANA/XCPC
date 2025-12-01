#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[110];
void solve () 
{
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    vector<int>ans;
    int c=0;
    for(int i=1;i<=n;i++) 
    if(a[i]==mx)
    {
        ans.push_back(1);
        c++;
    }
    else ans.push_back(2);
    if(c==n) cout<<"No\n";
    else 
    {
        cout<<"Yes\n";
        for(auto i:ans) cout<<i<<" ";
        cout<<"\n";
    }
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}