#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
int dp[100010];
int g[1<<20];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<(1<<m);i++) cin>>g[i];
    map<pair<int,int>,int>mp;
    mp[{(1<<m)-1,0}]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=-1e18;
        map<pair<int,int>,int>mpt;
        for(auto [x,y]:mp)
        {
            auto [sand,sor]=x;
            int new_sand=sand&a[i];
            int new_sor=sor|a[i];
            dp[i]=max(dp[i],y+g[new_sor-new_sand]);
            if(mpt.count({new_sand,new_sor})) mpt[{new_sand,new_sor}]=max(mpt[{new_sand,new_sor}],y);
            else mpt[{new_sand,new_sor}]=y;
        }
        if(mpt.count({(1<<m)-1,0})) mpt[{(1<<m)-1,0}]=max(dp[i],mpt[{(1<<m)-1,0}]);
        else mpt[{(1<<m)-1,0}]=dp[i];
        mp=mpt;
    }
    cout<<dp[n]<<"\n";
    // for(int i=1;i<=n;i++) cout<<dp[i]<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

