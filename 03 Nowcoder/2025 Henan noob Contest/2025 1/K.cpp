#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    vector<int>a;
    int n=4;
    for(int i=0;i<n;i++) a.push_back(i);
    do
    {
        int ans=0;
        for(int i=0;i<n;i++) ans+=(i!=a[i]);
        if(ans==n) 
        {
            for(auto i:a) cout<<i<<" ";
            cout<<"\n";
        }
    }while (next_permutation(a.begin(),a.end()));
    

}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}