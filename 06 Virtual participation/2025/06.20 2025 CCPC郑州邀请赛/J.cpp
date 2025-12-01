#include <bits/stdc++.h>
using namespace std;

int h[26] = 
{1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

void solve()
{
    string s;
    cin>>s;
    int res=0;
    for(int i=0;i<26;i++)
    {
        int ans=0;
        for(auto j:s)
        {
            int c=(j-'A')+i;
            c%=26;
            ans+=h[c];
        }
        // cout<<ans<<"?\n";
        res=max(res,ans);
    }
    cout<<res<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

