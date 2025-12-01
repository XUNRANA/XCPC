#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    stack<int>st;
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        int x;
        cin>>x;
        if(st.size()==0) st.push(x);
        else 
        {
            if(st.top()==x)
            {
                while(st.size()&&st.top()==x)
                {
                    x++;
                    st.pop();
                }
                st.push(x);
            }
            else 
            {
                if(st.size()<m) st.push(x);
                else break;
            }
        }
    }
    vector<int>ans;
    while(st.size())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    int f=0;
    for(auto i:ans) 
    {
        if(f) cout<<" ";
        cout<<i;
        f=1;
    }
    cout<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

