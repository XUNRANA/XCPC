#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    getline(cin,s);
    char p=' ';
    string ans;
    for(auto i:s)
    {
        if(i==' '&&p=='n')
        {
            ans+='g';
            ans+=i;
        }
        else ans+=i;
        p=i;
    }
    if(ans.size()&&ans.back()=='n') ans+="g";
    cout<<ans<<"\n";
}
int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}