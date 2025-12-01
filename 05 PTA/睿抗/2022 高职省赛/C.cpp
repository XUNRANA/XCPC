#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n,t;
    cin>>n>>t;
    while(n--)
    {
        string s;
        int x;
        cin>>s>>x;
        if(x<80-t||x>80+t) cout<<s<<" "<<x<<"\n";
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
