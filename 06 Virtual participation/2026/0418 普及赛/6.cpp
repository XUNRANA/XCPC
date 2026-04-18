#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x;
    set<int>st;
    int ans=-1;
    while(cin>>x)
    {
        if(x==-1) break;
        if(st.count(x)&&ans==-1) ans=x;
        st.insert(x);
    }
    if(ans==-1) cout<<"NONE\n";
    else cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}