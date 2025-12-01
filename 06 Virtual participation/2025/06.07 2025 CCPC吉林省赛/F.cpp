#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int se=0;
    int sf=0;
    int ans=0;
    s=" "+s;
    int ce=0;
    int cf=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='e') 
        {
            se+=i;
            ce++;
        }
        else if(s[i]=='f')
        {
            ans+=ce*i-se;
            //  cout<<ce*i-se<<"\n";
            sf+=i;
            cf++;
        }
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