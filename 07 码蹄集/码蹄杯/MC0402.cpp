#include <bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    string s;
    cin>>s;
    stack<pair<char,int>>st;
    int ans=0;
    int j=0;
    for(auto i:s)
    {
        if(st.empty()||st.top().first==i) 
        {
            st.push({i,j});
        }
        else 
        {
            if(i==')') 
            {
                st.pop();
            }
            else 
            {
                int l=st.top().second;
                ans+=(j-l+1)/2;
                st.pop();
            }
        }
        j++;
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
}

