#include <bits/stdc++.h>
using namespace std;
#define int long long

int p[200010];
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int sum=count(s.begin(),s.end(),'1');
    if(sum==n||sum==0)
    {
        cout<<"0\n";
        return ;
    }
    s=" "+s;
    for(int i=1;i<=n;i++) p[i]=p[i-1]+(s[i]=='1');
    set<int>st;
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        st.insert(2*p[i-1]-(i-1));
        ans=min(ans,sum+i-2*p[i]+(*st.begin()));
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