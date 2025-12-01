#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,x;
void solve()
{
    multiset<int>st;
    for(int i=0;i<8;i++)
    {
        cin>>x;
        st.insert(x);
        while(x<100&&st.count(x)==3)
        {
            st.erase(x);
            x*=10;
            st.insert(x);
        }
    }
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(st.size()<8) 
        {
            st.insert(x);
            while(x<100&&st.count(x)==3)
            {
                st.erase(x);
                x*=10;
                st.insert(x);
            }
        }
        else
        {
            if(st.count(x)==2)
            {
                st.insert(x);
                while(x<100&&st.count(x)==3)
                {
                    st.erase(x);
                    x*=10;
                    st.insert(x);
                }
            }
        }
    }
    cin>>m;
    int s=0;
    for(auto i:st) 
    {
        // cout<<i<<"\n";
        s=max(s,i);
    }
    if(s>=m) cout<<"YES YES YES\n";
    else cout<<"NO NO NO\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
