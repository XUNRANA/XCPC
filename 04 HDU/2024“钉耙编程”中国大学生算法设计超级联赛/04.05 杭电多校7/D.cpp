#include <bits/stdc++.h>
using namespace std;
vector<int>no[100010];
int n,s,r1,r2;

int dep[100010];
void dfs(int u,int fa)
{
    if(dep[u]>dep[s]) s=u;

    for(auto v:no[u])
    {
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}

void solve()
{
    cin>>n>>s>>r1>>r2;
    for(int i=1;i<=n;i++) no[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        no[x].push_back(y);
        no[y].push_back(x);
    }

    dep[s]=0;
    dfs(s,0);

    dep[s]=0;
    dfs(s,0);

    // cout<<dep[s]<<"\n";
    
    if(dep[s]>2*r1&&r2>2*r1) cout<<"General_Kangaroo"<<endl;
    else cout<<"Kangaroo_Splay"<<endl;
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
