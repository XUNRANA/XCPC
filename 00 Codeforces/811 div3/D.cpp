#include <bits/stdc++.h>
using namespace std;
#define int long long

string s[11];

void solve() 
{
    string t;
    int n;
    cin>>t;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    int l=t.size();
    t=" "+t;
    int lf=1,ri=1;
    vector<pair<int,int>>ans;
    while(1)
    { 
        int f=0;
        int mx=ri;
        int x=-1,y=-1;
        for(int i=ri;i>=lf;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i+s[j].size()-1<=l&&t.substr(i,s[j].size())==s[j])
                {
                    if(i+s[j].size()>mx)
                    {
                        mx=i+s[j].size();
                        x=j;
                        y=i;
                    }
                }
            }
        }
        if(mx>ri)
        {
            ri=mx;
            lf=y+1;
            ans.push_back({x,y});
        }
        else break;
    }

    if(ri==l+1)
    {
        cout<<ans.size()<<"\n";
        for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
    }
    else cout<<"-1\n";
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