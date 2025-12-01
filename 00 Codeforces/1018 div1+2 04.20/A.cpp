#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    string s;
    int n;
    cin>>n>>s;
    int j=1;
    vector<int>ans(s.size()+2,0);
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='<') ans[i+2]=j++;
    }
    for(int i=1;i<=s.size()+1;i++) if(!ans[i]) ans[i]=j++;
    for(int i=1;i<=s.size()+1;i++) cout<<ans[i]<<" \n"[i==s.size()+1];
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