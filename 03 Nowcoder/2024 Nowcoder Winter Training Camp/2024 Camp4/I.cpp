#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>>g[200010];
int dis[200010][2];
bool cmp(pair<int,int> x,pair<int,int> y)
{
    return x.second<y.second;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
	{
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++)
	{
        if(i>1)dis[i][0]=dis[i][1]=1e18;
        sort(g[i].begin(),g[i].end(),cmp);
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    q.push({0,{1,0}});
    q.push({0,{1,1}});
    while(!q.empty())
	{
        int w=q.top().first;
        int now=q.top().second.first;
        int p=q.top().second.second;
        q.pop();
        if(w>dis[now][p]) continue;
        if(p==0)
		{
            for(int i=1;i<g[now].size();i++)
			{
                int v=g[now][i].first,w=g[now][i].second;
                int tmp=1e9;
                if(!g[v].empty()) tmp=g[v][0].second;
                if(dis[v][0]>dis[now][p]+min(w,tmp))
				{
                    dis[v][0]=dis[now][p]+min(w,tmp);
                    q.push({dis[v][0],{v,0}});
                }
                tmp=1e9;
                if(g[v].size()>1)tmp=g[v][1].second;
                if(dis[v][1]>dis[now][p]+min(w,tmp))
				{
                    dis[v][1]=dis[now][p]+min(w,tmp);
                    q.push({dis[v][1],{v,1}});
                }
            }
        }
        else
		{
            for(int i=0;i<min((int)g[now].size(),1ll);i++)
			{
                int v=g[now][i].first,w=g[now][i].second;
                int tmp=1e9;
                if(!g[v].empty()) tmp=g[v][0].second;
                if(dis[v][0]>dis[now][p]+min(w,tmp))
				{
                    dis[v][0]=dis[now][p]+min(w,tmp);
                    q.push({dis[v][0],{v,0}});
                }
                tmp=1e9;
                if(g[v].size()>1) tmp=g[v][1].second;
                if(dis[v][1]>dis[now][p]+min(w,tmp))
				{
                    dis[v][1]=dis[now][p]+min(w,tmp);
                    q.push({dis[v][1],{v,1}});
                }
            }
        }
    }
    
    if(min(dis[n][0],dis[n][1])<1e18) cout<<min(dis[n][0],dis[n][1]);
    else cout<<"-1";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
