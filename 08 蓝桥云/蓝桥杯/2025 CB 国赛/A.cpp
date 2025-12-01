#include <bits/stdc++.h>
using namespace std;
#define int long long

bool is(string s)
{
    int f1=0,f2=0;
    for(auto i:s)
    if(isdigit(i)) f1=1;
    else if(i=='#') f2=1;
    return f1&&f2;
}
void solve()
{
    string s="kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
    int n=s.size();
    s=" "+s;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=8;j<=16;j++)
        {
            if(i+j-1<=n&&is(s.substr(i,j))) ans++;
        }
    }
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}