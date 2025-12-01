#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010];
void solve() 
{
    int n,q,p,x;
    cin>>n>>q>>p;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--)
    {
        cin>>x;
        if(x>p) cout<<"Noob\n";
        else 
        {
            priority_queue<pair<long long,int>>pq;
            pq.push({0,0});
            for(int i=1;i<=n/x;i++)
            {
                while((i-pq.top().second)*x>p) pq.pop();
                pq.push({pq.top().first+a[i*x],i});
            }
            while(n+1-pq.top().second*x>p) pq.pop();
            cout<<pq.top().first<<"\n";
        } 
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}