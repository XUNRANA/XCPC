#include <bits/stdc++.h>
using namespace std;

const int M=1000010;
int n,m,a[1010][1010];

int h[M];
struct edge{
    int to;
    int next;
}g[M];
int in[M];
int idx;
void add(int u,int v)
{
    g[idx].to=v;
    g[idx].next=h[u];
    h[u]=idx;
    idx++;
}

void solve()
{
    cin>>n>>m;
    int cnt=0;
    memset(h,-1,sizeof(int)*M);
    memset(in,-1,sizeof(int)*M);

    for(int i=1;i<=n;i++) 
    for(int j=1;j<=m;j++) 
    {
        cin>>a[i][j];
        if(in[a[i][j]]==-1)
        {
            in[a[i][j]]=0;
            cnt++;
        }
        if(i>1)
        {
            if(a[i-1][j]!=a[i][j])
            {
                add(a[(i&1)^1][j],a[i&1][j]);
                in[a[i&1][j]]++;
            }
        }
    }


    priority_queue<int,vector<int>,greater<int>>q;
    
    for(int i=0;i<M;i++) if(!in[i]) q.push(i);
    vector<int>ans;

    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        ans.push_back(u);
        for(int i=h[u];i!=-1;i=g[i].next)
        {
            int v=g[i].to;
            if(--in[v]==0) q.push(v);
        }
    }

    int f=0;
    for(auto i:ans) 
    {
        if(f) cout<<" ";
        cout<<i;
        f=1;
    }
    if(ans.size()!=cnt)
    {
        if(ans.size()) cout<<" ";
        cout<<"Impossible";
    }
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
