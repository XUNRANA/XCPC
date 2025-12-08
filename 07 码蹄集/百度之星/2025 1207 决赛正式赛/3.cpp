#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[210],b[210];
int bp[210];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<int>p;
    for(int i=1;i<=n;i++) p.push_back(i);
    do
    {
        for(auto i:p) cout<<a[i]<<" ";
        cout<<"\n";

        for(auto i:p) cout<<b[i]<<" ";
        cout<<"!!!!\n";

    }while(next_permutation(p.begin(),p.end()));
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}