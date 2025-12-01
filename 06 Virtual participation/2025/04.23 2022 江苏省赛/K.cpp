#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
    int n;
    cin>>n;
    string ans="nunhehhe";
    string res="";
    vector<int>b;
    while(n)
    {
        int x=(1ll<<__lg(n+1))-1;
        b.push_back(__lg(n+1));
        n-=x;
    }
    reverse(b.begin(),b.end());
    int cnt=0;//a 
    for(auto i:b)
    {
        while(cnt<i)
        {
            cnt++;
            res='a'+res;
        }
        res='h'+res;
    }
    cout<<ans+res<<"\n";
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