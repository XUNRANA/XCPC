#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
void solve()
{
    cin>>n;
    int ans=0;
    int mx=0;
    while(n--)
    {
        string s;
        cin>>s;
        int c1=0,c2=0;
        for(auto i:s) 
        if(i=='1') c1++;
        else c2++;

        if(!c2) ans+=c1;
        else 
        {
            int x1=s.find('0');
            int x2=s.size()-1-s.rfind('0');
            mx=max(mx,max(x1,x2));
        }
    }
    cout<<ans+mx<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
