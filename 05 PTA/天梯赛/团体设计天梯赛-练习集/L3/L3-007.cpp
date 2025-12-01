#include <bits/stdc++.h>
using namespace std;
#define int long long

//最快最短
//最短、节点最少
int n,m;
vector<array<int,3>>G[510];
vector<int>ans1;
vector<int>ans2;
int res1;
int res2;
void dij1(int s,int t)
{
    vector<int>d1(n,1e9);//最快
    vector<int>d2(n,1e9);//最短
    vector<int>vt(n,0);
    vector<int>pre(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    d1[s]=d2[s]=0;
    q.push({d1[s],s});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto i:G[u])
        {
            int v=get<0>(i);
            int l=get<1>(i);
            int t=get<2>(i);
            if(d1[v]>d1[u]+t)
            {
                d1[v]=d1[u]+t;
                d2[v]=d2[u]+l;
                pre[v]=u;
                q.push({d1[v],v});
            }
            else if(d1[v]==d1[u]+t)
            {
                if(d2[v]>d2[u]+l) 
                {
                    d2[v]=d2[u]+l;
                    pre[v]=u;
                }
            }
        }
    }
    res2=d1[t];
    while(t!=s)
    {
        ans1.push_back(t);
        // cout<<t<<" ";
        t=pre[t];
    }
    ans1.push_back(t);
    // cout<<s<<"\n";
}
void dij2(int s,int t)
{
    vector<int>d1(n,1e9);//最短
    vector<int>d2(n,1e9);//最少节点数
    vector<int>vt(n,0);
    vector<int>pre(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    d1[s]=d2[s]=0;
    q.push({d1[s],s});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto i:G[u])
        {
            int v=get<0>(i);
            int l=get<1>(i);
            int t=get<2>(i);
            if(d1[v]>d1[u]+l)
            {
                d1[v]=d1[u]+l;
                d2[v]=d2[u]+1;
                pre[v]=u;
                q.push({d1[v],v});
            }
            else if(d1[v]==d1[u]+l)
            {
                if(d2[v]>d2[u]+1) 
                {
                    d2[v]=d2[u]+1;
                    pre[v]=u;
                }
            }
        }
    }
    res1=d1[t];
    while(t!=s)
    {
        ans2.push_back(t);
        // cout<<t<<" ";
        t=pre[t];
    }
    ans2.push_back(t);
    // cout<<s<<"\n";
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,f,l,t;
        cin>>u>>v>>f>>l>>t;
        G[u].push_back({v,l,t});
        if(!f) G[v].push_back({u,l,t});
    }
    int s,t;
    cin>>s>>t;
    dij1(s,t);
    dij2(s,t);
    for(int i=0;i<ans1.size()/2;i++) swap(ans1[i],ans1[ans1.size()-1-i]);
    for(int i=0;i<ans2.size()/2;i++) swap(ans2[i],ans2[ans2.size()-1-i]);
    if(ans1!=ans2)
    {
        cout<<"Time = "<<res2<<": ";
        int f=0;
        for(auto i:ans1)
        {
            if(f) cout<<" => ";
            cout<<i;
            f=1;
        }
        cout<<"\n";

        cout<<"Distance = "<<res1<<": ";
        f=0;
        for(auto i:ans2)
        {
            if(f) cout<<" => ";
            cout<<i;
            f=1;
        }
        cout<<"\n";
    }
    else
    {
        cout<<"Time = "<<res2<<"; "<<"Distance = "<<res1<<": ";
        int f=0;
        for(auto i:ans1)
        {
            if(f) cout<<" => ";
            cout<<i;
            f=1;
        }
        cout<<"\n";
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}