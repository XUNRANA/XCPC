#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    set<int>st;
    for(int i=2;i<=n;i++) st.insert(a[i]-a[i-1]);

    if(st.size()==1)
    {
        int x=*st.begin();
        if(x>0) a[1]-=x;
        else a[1]+=x*n;
        if(a[1]>=0&&a[1]%(n+1)==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    else cout<<"NO\n";
    
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