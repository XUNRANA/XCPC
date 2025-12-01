#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    string ans="";
    int f=0;
    for(int i=0;i<s.size();i++)
    {
        if(i+1<s.size()&&i+2<s.size()&&s[i]==':'&&s[i+1]=='/'&&s[i+2]=='/')
        {
            f=1;
            cout<<ans<<"\n";
            ans="";
            i+=2;
        }
        else if(f&&s[i]=='/')
        {
            
            if(f==1||ans.find('=')!=-1) 
            {
                cout<<ans<<"\n";
                f=2;
            }
            ans="";
        }
        else ans+=s[i];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}