#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
    int n,k,x,m;
    cin>>n>>k;
    int ans=0;
    vector<int>a;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        ans+=x/k;
        a.push_back(x%k);
    }
    sort(a.begin(),a.end(),greater<int>());
    cin>>m;
    for(auto i:a)
    {
        if(m>=k-i)
        {
            m-=k-i;
            ans++;
        }
    }
    ans+=m/k;
    cout<<ans<<"\n";
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