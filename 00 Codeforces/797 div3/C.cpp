#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int s[200010];
int f[200010];
int ans[200010];
void solve() 
{

    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>f[i];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({f[1],1});
    int last=s[1];
    int i=2;
    while(!q.empty())
    {
        int now=q.top().first;
        ans[q.top().second]=now-last;
        last=now;
        q.pop();
        while(i<=n&&s[i]<=now) 
        {
            q.push({f[i],i});
            i++;
        }
        if(q.empty()&&i<=n)
        {
            last=now=s[i];
            q.push({f[i],i});
            i++;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
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