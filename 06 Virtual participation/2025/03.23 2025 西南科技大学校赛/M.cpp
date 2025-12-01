#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<array<int,4>>G[50010];
void solve()
{
    int n,m,s,t,u,v,w,g,r,st,d;
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++) 
    {
        cin>>u>>v>>w>>g>>r;
        G[u].push_back({v,w,g,r});
    }
    vector<vector<int>>dis(n+1,vector<int>(3,1e18));
    vector<vector<int>>vt(n+1,vector<int>(3,0));
    dis[s][0]=0;//s点，使用零次，距离0
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    q.push({0,0,s});//距离 次数 位置
    while(!q.empty())
    {
        auto [d,cnt,u]=q.top();
        q.pop();
        if(vt[u][cnt]) continue;
        vt[u][cnt]=1;
        for(auto [v,w,g,r]:G[u])
        {
            int now=d%(g+r);
            int res=g-now;//还剩多少安全通过的时间
            if(res>=w)//可以安全通过
            {
                if(dis[v][cnt]>d+w)//更新
                {
                    dis[v][cnt]=d+w;
                    q.push({dis[v][cnt],cnt,v});
                }
            }
            else
            {
                int nd=g+r-now+w+d;//需要等一会
                if(dis[v][cnt]>nd)//更新
                {
                    dis[v][cnt]=nd;
                    q.push({dis[v][cnt],cnt,v});
                }

                if(cnt+1<3&&dis[v][cnt+1]>d+w)//使用次数
                {
                    dis[v][cnt+1]=d+w;
                    q.push({dis[v][cnt+1],cnt+1,v});
                }
            }
        }
    }
    int ans=1e18;
    for(int i=0;i<3;i++) ans=min(ans,dis[t][i]);
    if(ans==1e18) ans=-1;
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
