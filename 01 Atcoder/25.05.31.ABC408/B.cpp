#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n,x;
    cin>>n;
    set<int>st;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<"\n";
    for(auto i:st) cout<<i<<" ";
    cout<<"\n";

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