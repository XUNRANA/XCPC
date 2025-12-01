#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,k;
    cin>>n>>k;
    set<int>st;
    while(n--)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    vector<int>a;
    for(auto i:st) a.push_back(i);
    
    if(a.size()>=k) cout<<a[k-1]<<"\n";
    else cout<<"-1\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}