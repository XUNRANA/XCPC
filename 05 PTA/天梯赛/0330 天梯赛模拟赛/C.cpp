#include <bits/stdc++.h>
using namespace std;
#define int long long
string t="shinto mekkaku";
void solve() 
{
    string s,ans="";
    getline(cin,s);
    for(auto i:s) 
    if(isupper(i)) ans+=tolower(i);
    else ans+=i;
    if(ans.find(t)!=-1) cout<<"Medaka Kuroiwa\n";
    else cout<<"Bonnjinn\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    cin.ignore();
    while(T--) solve();
}