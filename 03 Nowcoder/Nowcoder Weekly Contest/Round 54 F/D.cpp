#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1010],dis[1010],vt[1010];
vector<int>g[1010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) 
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]%(j-i)==0) g[i].push_back(j);
            if(a[j]%(j-i)==0) g[j].push_back(i);
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
    for(int i=1;i<=n;i++) 
    {
        dis[i]=i-1;
        q.push({i-1,i});
    }
    while(!q.empty())
    {
        int d=q.top().first;
        int u=q.top().second;
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto v:g[u])
        {
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                q.push({dis[v],v});
            }
        }
    }
    cout<<dis[n]<<"\n";
    //for(int i=1;i<=n;i++) cout<<dis[i]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
