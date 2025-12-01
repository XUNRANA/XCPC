#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n;
    cin>>n;
    map<string,int>mp;
    for(int i=1;i<=n;i++)
    {
        string s;
        char ch;
        cin>>s>>ch;
        mp[s]=(ch=='e');
    }
    int m;
    cin>>m;
    int fl=0;
    for(int i=1;i<=m;i++)
    {
        int k;
        cin>>k;
        int f=0;
        for(int j=1;j<=k;j++) 
        {
            string s;
            cin>>s;
            f|=mp[s];
        }
        if(!f) 
        {
            if(fl) cout<<" ";
            cout<<i;
            fl=1;
        } 
    }
    if(!fl) cout<<"None\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

