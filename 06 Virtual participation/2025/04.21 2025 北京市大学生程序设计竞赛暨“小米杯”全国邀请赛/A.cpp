#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    if(s[0]!=s.back())
    {
        cout<<"empty\n";
        return ;
    }
    string t="";
    if(s[0]=='1') t="00";
    else t="11";
    if(s.find(t)!=s.npos)
    {
        cout<<"empty\n";
        return ;
    }

    int mi=1e9;
    int l=1;
    for(int i=1;i<s.size();i++)
    if(s[i]==s[i-1]) l++;
    else
    {
        if(s[i-1]==s[0]) mi=min(mi,l);
        l=1;
    }
    mi=min(mi,l);
    while(mi--) cout<<s[0];
    cout<<"\n";

}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}