#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1),b(m+1),c(m+1);
    map<int,int>fa;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i]>>c[i];
    for(int i=m;i>=1;i--) 
    if(fa.count(c[i])) fa[b[i]]=fa[c[i]];
    else fa[b[i]]=c[i]; 
    for(int i=1;i<=n;i++) if(!fa[a[i]]) cout<<a[i]<<" ";
    else cout<<fa[a[i]]<<" ";
    cout<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--) solve();
}