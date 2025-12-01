#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>g[900010];
int in[900010];
int n,m;
bool fx()
{
    queue<int>q;
    for(int i=1;i<=3*n;i++) if(!in[i]) q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:g[u])
        {
            if(--in[v]==0) q.push(v);
        }
    }
    for(int i=1;i<=3*n;i++) if(in[i]) return 0;
    return 1;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=3*n;i++) g[i].clear(),in[i]=0;
    int f=1;
    for(int i=1;i<=m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        int p=(y+1)/2,q=2*n-x+1,r=2*n+x-y/2;
        if(!f) continue;
        if(c!=p&&c!=q&&c!=r) 
        {
            f=0;
            continue;
        }
        if(c==p)
        {
            g[q].push_back(c);
            g[r].push_back(c);
        }
        else if(c==q)
        {
            g[p].push_back(c);
            g[r].push_back(c);
        }
        else if(c==r)
        {
            g[p].push_back(c);
            g[q].push_back(c);
        }
        in[c]+=2;
    }
    if(!f) 
    {
        cout<<"No\n";
        return ;
    }
    if(fx()) cout<<"Yes\n";
    else cout<<"No\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

