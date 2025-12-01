#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
void solve()
{
    cin>>n>>d;
    vector<int>a;
    for(int i=0;i<d;i++) a.push_back(i);
    int cnt=0;
    do
    {
        int t=n-d;
        while(t--) cout<<"0 ";
        for(auto i:a) cout<<i<<" ";
        cout<<"\n";
        cnt++;
        if(cnt==n) return;
    } while (next_permutation(a.begin(),a.end()));
    

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}