#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') ans+=n-i;
        else ans+=2*(n-i);
        if(i+1<n)
        {
            int t=0;
            if(s[i]!=s[i+1]) t=1*(i+1)*(n-i-1);
            else t=2*(i+1)*(n-i-1);
            ans+=t;
        }
    }
    cout<<ans<<"\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}