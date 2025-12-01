#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    set<int>st,st1;
    st.insert(a[1]);
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        st1.insert(a[i]);
        if(st.count(a[i]))
        {
            st.erase(st.find(a[i]));
            if(st.size()==0)
            {
                ans++;
                st=st1;
                st1.clear();
            }
        }
    }
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