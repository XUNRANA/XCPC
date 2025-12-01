#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[300010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>p[i],p[i]+=p[i-1];
    multiset<int>st;
    int ans=-1e18;
    for(int i=1;i<=n;i++)
    {
        st.insert(p[i-1]);
        if(i>m) st.erase(st.find(p[i-m-1]));
        ans=max(ans,p[i]-(*st.begin()));
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
