#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
    string s;
    map<char,set<string>>mp[2];
    while(getline(cin,s))
    {
        int f=0;
        for(auto i:s) if(i==' ') f=1;
        char ch=s[0];
        if(islower(ch)) ch=toupper(ch); 
        if(f) mp[1][ch].insert(s);
        else mp[0][ch].insert(s);
    }
    for(int i=0;i<26;i++)
    {
        char ch='A'+i;
        int cnt=(int)mp[0][ch].size()+(int)mp[1][ch].size();
        if(!cnt) continue;
        cout<<ch<<" "<<cnt<<"\n";
        for(auto i:mp[0][ch]) cout<<i<<"\n";
        for(auto i:mp[1][ch]) cout<<i<<"\n";
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}