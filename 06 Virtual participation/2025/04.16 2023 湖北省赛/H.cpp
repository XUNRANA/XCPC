#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e6;
constexpr ll P = 998244353;
#define int long long
int n,m,u,v;
int d[1000010];
void solve() 
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        d[u]++;
        d[v]++;
    }
    map<int,int>mp;
    vector<int>a;
    for(int i=1;i<=n;i++) if(d[i]) mp[d[i]]++;
    // for(auto i:mp) cout<<i.first<<" "<<i.second<<"\n";
    for(auto i:mp) a.push_back(i.first);
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            // cout<<a[i]<<" "<<a[j]<<" "<<(a[i]&a[j])*(a[i]|a[j])*(a[i]^a[j])*mp[a[i]]*mp[a[j]]<<"\n";
            ans+=(a[i]&a[j])*(a[i]|a[j])%P*(a[i]^a[j])%P*mp[a[i]]%P*mp[a[j]]%P;
            ans%=P;
        }
    }
    cout<<ans<<"\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}