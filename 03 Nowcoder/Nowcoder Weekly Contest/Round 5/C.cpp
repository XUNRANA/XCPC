#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<int>g[1010];
string s;
int n,l,r,u,v,ans;
void dfs(int u,int fa,int sum)
{
    if(sum>=l&&sum<=r&&fa!=0) ans++;
    else if(sum>r) return ;
    
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u,sum*2+s[v]-'0');
    }
}
void solve()
{ 
    cin>>n>>l>>r>>s;
    s=" "+s;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) dfs(i,0,s[i]-'0');
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
