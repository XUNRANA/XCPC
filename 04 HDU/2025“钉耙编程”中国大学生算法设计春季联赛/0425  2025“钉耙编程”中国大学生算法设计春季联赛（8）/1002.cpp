#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[5010];
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int s=0;
    for(int i=0;i<=5000;i++) dp[i]=0;
    for(int i=1;i<=n;i++)
    {
        int sx=0,sy=0;
        vector<pair<int,int>>a;
        for(int j=1;j<=m;j++)
        {
            int x,y;
            cin>>x>>y;
            s+=y;
            sx+=x;
            sy+=y;
            if(sx<=k) a.push_back({sx,sy});
        }
        for(int j=k;j>=1;j--)
        {
            for(auto i:a)
            {
                if(j>=i.first)
                {
                    dp[j]=max(dp[j-i.first]+i.second,dp[j]);
                } 
            }
        }
    }
    cout<<s-dp[k]<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
