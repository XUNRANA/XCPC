#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int ans=0;

    for(int i=1;i<=10;i++)
    for(int j=1;j<=10;j++)
    for(int k=1;k<=10;k++)
    {
        set<int>s1,s2;
        s1.insert(i);
        s1.insert(j);
        s1.insert(k);

        
        s2.insert(i+j);
        s2.insert(j+k);
        s2.insert(i+k);


        int f=0;
        for(auto i:s1) if(!s2.count(i)) f=1;
        if(!f) ans++;
    }
    cout<<ans<<"\n";

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