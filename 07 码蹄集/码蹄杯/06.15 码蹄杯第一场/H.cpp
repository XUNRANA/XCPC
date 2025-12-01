#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(i+5<s.size()&&s.substr(i,6)=="matiji")
        {
            ans++;
            i+=5;
        }
    }
    cout<<ans<<"\n";
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}