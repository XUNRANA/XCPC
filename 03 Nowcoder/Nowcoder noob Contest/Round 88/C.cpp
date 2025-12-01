#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,h,m;
    cin>>n;
    set<pair<int,int>>s;
    for(int i=1;i<=n;i++) 
    {
        cin>>h>>m;
        if(m-1>=0) s.insert({h,m-1});
        else 
        {
            if(h==0) s.insert({23,60+m-1});
            else s.insert({h-1,60+m-1});
        }
        if(m-5>=0) s.insert({h,m-5});
        else 
        {
            if(h==0) s.insert({23,60+m-5});
            else s.insert({h-1,60+m-5});
        }
        if(m-3>=0) s.insert({h,m-3});
        else 
        {
            if(h==0) s.insert({23,60+m-3});
            else s.insert({h-1,60+m-3});
        }
    }
    cout<<s.size()<<"\n";
    for(auto i:s) cout<<i.first<<" "<<i.second<<"\n";
}