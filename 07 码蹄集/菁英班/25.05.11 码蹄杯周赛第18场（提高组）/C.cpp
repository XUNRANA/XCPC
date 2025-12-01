#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[2010];
int b[2010];
int c[2010];
bool ck(int x)
{
    for(int i=1;i<=n;i++) c[i]=x^a[i];
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++) if(c[i]!=b[i]) return 0;
    return 1;
}
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(b+1,b+1+n);
    set<int>st;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) st.insert(a[i]^b[j]);
    vector<int>ans;
    for(auto i:st) if(ck(i)) ans.push_back(i);
    cout<<ans.size()<<"\n";
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}