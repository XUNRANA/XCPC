#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve() 
{
    int n,m,s,t;
    cin>>n>>m;
    vector<array<int,3>>a;
    for(int i=1;i<=n;i++)
    {
        cin>>s>>t;
        a.push_back({s,t,1});
    }
    for(int i=1;i<=m;i++)
    {
        cin>>s>>t;
        a.push_back({s,t,0});
    }
    sort(a.begin(),a.end());
    int mx=0;//清醒的最大时刻
    int pt1=0;
    int pt2=0;
    for(auto i:a)
    {
        // cout<<mx<<"\n";
        int s=get<0>(i);
        int t=get<1>(i);
        int f=get<2>(i);
        if(!f) 
        {
            if(s<pt2)
            {
                cout<<"No\n";
                return ;
            }
            mx=t+2*(t-s);
            pt1=t;
        }
        else 
        {
            if(s<pt1||t>mx)
            {
                cout<<"No\n";
                return ;
            }
            pt2=t;
        }
    }
    cout<<"Yes\n";
}

signed main() 
{

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}