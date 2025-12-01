#include <bits/stdc++.h>
using namespace std;


void solve()
{
    string s;
    cin>>s;
    int cnt=0;
    string t=s.substr(0,1000);
    for(int i=0;i+999<s.size();i++)
    {
        if(t==s.substr(i,1000))
        {
            cnt++;
            i+=999;
        }
    }
    if(cnt<100) cout<<"Yes\n";
    else cout<<"No\n";
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}