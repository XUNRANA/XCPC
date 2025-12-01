#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
int b[200010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<int>aa;
    for(int i=1;i<=n;i++) 
    {
        int c;
        cin>>c;
        if(c) aa.push_back(a[i]); 
    }
    int j=0;
    for(int i=1;i<=n;i++) if(j<aa.size()&&b[i]==aa[j]) j++;
    if(j==aa.size()) cout<<"Yes\n";
    else cout<<"No\n";
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