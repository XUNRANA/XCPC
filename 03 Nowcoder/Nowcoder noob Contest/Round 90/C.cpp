#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
    cin>>s;
    string ans;
    if(s.size()==1) 
    {
        cout<<"1\n";
        return ;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0') ans+='1';
        else ans+='0';
    }
    for(int i=0;i<ans.size();i++) 
    if(ans[i]!='0') 
    {
        cout<<ans.substr(i)<<"\n";
        return ;
    }
    int c=s[s.size()-1]-'0';
    if(c!=1) cout<<"1\n";
    else cout<<"2\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--) solve();
}