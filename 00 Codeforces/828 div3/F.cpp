#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve () 
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int>aa,bb;
    for(int i=1;i*i<=a;i++)
    {
        if(a%i==0)
        {
            aa.push_back(i);
            if(a/i!=i) aa.push_back(a/i);
        }
    }
    for(int i=1;i*i<=b;i++)
    {
        if(b%i==0)
        {
            bb.push_back(i);
            if(b/i!=i) bb.push_back(b/i);
        }
    }
    for(auto i:aa)
    {
        for(auto j:bb)
        {
            int n=i*j;
            int m=a/i*b/j;
            int ans1=c/n*n;
            int ans2=d/m*m;
            if(ans1>a&&ans2>b)
            {
                cout<<ans1<<" "<<ans2<<"\n";
                return ;
            }
        }
    }
    cout<<"-1 -1\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}