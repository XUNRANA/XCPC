#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    queue<array<int,2>> pq;
    pq.push({0,n});
    set<int> vis;
    while(!pq.empty())
    {
        auto t=pq.front();
        pq.pop();
        int time=t[0],val=t[1];
        if(val==k)
        {
            cout<<time<<"\n";
            return;
        }
        if(val/2>=k&&vis.find(val/2)==vis.end()) 
        {
            pq.push({time+1,val/2});
            vis.insert(val/2);
        }
        if((val&1)&&(val/2+1>=k)&&vis.find(val/2+1)==vis.end()) 
        {
            pq.push({time+1,val/2+1});
            vis.insert(val/2+1);
        }
    }
    cout<<-1<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}