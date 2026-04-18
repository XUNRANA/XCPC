#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    if(s.size()==2)
    {
        if(s[0]==s[1]) cout<<"1\n";
        else cout<<"0\n";
    }
    else 
    {
        int f=0;
        for(int i=0;i<s.size()-1;i++) if(s[i]==s[i+1]) f=1;
        if(f) cout<<s.size()-1<<"\n";
        else cout<<s.size()-2<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}