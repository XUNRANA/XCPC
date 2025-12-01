#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    string s;
    int t,n;
    cin>>s>>t;
    n=s.size();
    vector<int>f(n,0);
    int cnt=0;
    for(int j=0;j<26;j++)
    for(int i=0;i<n;i++) 
    {
        if(s[i]-'a'==j)
        {
            if(cnt+j+1<=t)
            {
                cnt+=j+1;
                f[i]=1;
            }
        }
    }
    for(int i=0;i<n;i++) if(f[i]) cout<<s[i];
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