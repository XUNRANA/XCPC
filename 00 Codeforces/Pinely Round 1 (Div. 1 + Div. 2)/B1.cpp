#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    cin>>n;
    set<int>st;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    if(n%2==0&&st.size()==2) cout<<n/2+1<<"\n";
    else cout<<n<<"\n";
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