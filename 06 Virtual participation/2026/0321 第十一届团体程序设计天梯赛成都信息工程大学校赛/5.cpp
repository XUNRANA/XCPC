#include <bits/stdc++.h>
using namespace std;
int is(int x)
{
    if(x==1) return 0;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
void solve()
{
    int n;
    cin>>n;
    set<int>st;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0) 
        {
            st.insert(i);
            st.insert(n/i);
        }
    }
    int ans=0;
    for(auto i:st) if(i!=n&&!is(i)) ans+=i;
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}