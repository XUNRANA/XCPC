#include <bits/stdc++.h>
using namespace std;
vector<int>st[3];
void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>>ans;
    if(n<6)
    {
        int i=2;
        while(ans.size()<n) ans.push_back({1,i++});
    }
    else if(n<9)//两个
    {
        ans.push_back({1,2});
        ans.push_back({1,3});
        ans.push_back({1,4});
        ans.push_back({2,3});
        ans.push_back({2,4});
        int i=5;
        while(ans.size()<n) ans.push_back({1,i++});
    }
    else
    {
        int cnt=n/3;
   
        ans.push_back({1,3});
        ans.push_back({2,3});
        ans.push_back({3,cnt+1});
        
        ans.push_back({1,2});
        ans.push_back({2,cnt+1});
        ans.push_back({2,cnt+2});

        ans.push_back({1,cnt+1});
        ans.push_back({1,cnt+2});
        ans.push_back({1,cnt+3});
        for(int i=4;i<=cnt;i++) 
        {
            ans.push_back({1,i});
            ans.push_back({2,i});
            ans.push_back({3,i});
        }
        int i=cnt+4;
        while(ans.size()<n) ans.push_back({1,i++});
    }
    // cout<<ans.size()<<"\n";
    sort(ans.begin(),ans.end());
    for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";

} 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}