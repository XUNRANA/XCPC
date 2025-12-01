#include <bits/stdc++.h>
using namespace std;
int n,x,f,dp[100010],ans[100010];
string s;
vector<int>g[100010];
void dfs(int u)
{
    if(!g[u].size())
    {
        if(s[u]=='R') f=1;
        else ans[u]=dp[u]=2;
        return ;
    }
    
    for(auto v:g[u])
    {
        dfs(v);
        dp[u]=(dp[u]+dp[v])%3;
    }
    
    if(s[u]=='R')
    {
        if(dp[u]==1) ans[u]=2;
        else if(dp[u]==2) ans[u]=1;
        else 
        {
            int fx=0;
            for(auto v:g[u])
            {
                if(ans[v]==2&&s[v]=='W')
                {
                    ans[v]=1;
                    ans[u]=1;
                    fx=1;
                    break;
                }
                if(ans[v]==1&&s[v]=='W')
                {
                    ans[v]=2;
                    ans[u]=2;
                    fx=1;
                    break;
                }
                
            }
            if(fx==0) f=1;
        }
        dp[u]=0;
    }
    else 
    {
        ans[u]=2;
        dp[u]=(dp[u]+2)%3;
    }
}

void solve()
{
    cin>>n>>s;
	s=" "+s;
	for(int i=2;i<=n;i++) 
	{
		cin>>x;
		g[x].push_back(i);
	}
	dfs(1);
	if(f) cout<<"-1\n";
	else for(int i=1;i<=n;i++) cout<<ans[i];
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
