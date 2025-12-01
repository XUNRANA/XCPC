#include <bits/stdc++.h>
using namespace std;

int c[4][26];
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++) c[i%4][s[i]-'a']++;
    

    int ans=0;
    int r1;
    string t="blue";
    for(int i=0;i<4;i++)
    {
        int res=n;
        for(int j=0;j<4;j++)
        {
            res=min(res,c[(i+j)%4][t[j]-'a']);
        }
        if(!i) r1=res;
        ans+=res;
    }
    if(ans*4==s.size()&&ans!=r1) ans--;
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}