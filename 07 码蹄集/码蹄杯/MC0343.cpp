#include <bits/stdc++.h>
using namespace std;
#define int long long


struct node
{
    int x,y;
}a[100010];
bool cmp(node a1,node a2)
{
    if(a1.y==a2.y) return a1.x>a2.x;
    return a1.y<a2.y;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n,cmp);
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=1;i<=n;i++)
    {
        if(a[i].y>q.size()) 
        {
            q.push(a[i].x);
        }
        else if(a[i].y==q.size())
        {
            if(a[i].x>q.top())
            {
                q.pop();
                q.push(a[i].x);
            }
        } 
    }
    int ans=0;
    while(!q.empty()) ans+=q.top(),q.pop();
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
