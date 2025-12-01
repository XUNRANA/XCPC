#include <bits/stdc++.h>
using namespace std;
#define int long long 
void solve() 
{
    int n;
    string s;
    cin>>n>>s;
    int x=0,y=0;
    int d=0;
    map<pair<int,int>,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[{x,y}]=1;
        if(s[i]=='L') d--;
        else if(s[i]=='R') d++;
        d=(d+4)%4;
        if(d==0) x++;
        else if(d==1) y++;
        else if(d==2) x--;
        else if(d==3) y--;
        if(i<n-1&&mp.count({x,y})) 
        {
            cout<<"-1\n";
            return ;
        }
    }
    if(!x&&!y&&!d) cout<<"1\n";
    else cout<<"0\n";
}

signed main() 
{

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}