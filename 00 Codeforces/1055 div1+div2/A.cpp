#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,x;
    cin>>n;
    set<int>st;
    while(n--)
    {
        cin>>x;
        st.insert(x);
    }
    if(st.size()==1) cout<<"1\n";
    else cout<<2*st.size()-1<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}