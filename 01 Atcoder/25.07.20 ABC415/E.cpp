#include <bits/stdc++.h>
using namespace std;
#define int long long
int h,w;
void solve()
{
    cin>>h>>w;
    vector<vector<int>>a(h+1,vector<int>(w+1,0));
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin>>a[i][j];
        }
    }

    vector<int>b(h+w);
    for(int i=1;i<=h+w-1;i++) cin>>b[i];



    // for(int i=1;i<=h;i++)
    // {
    //     for(int j=1;j<=w;j++)
    //     {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }


    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            a[i][j]-=b[i+j-1];
        }
    }


    int l=0,r=2e14;
    while(l<=r)
    {
        int m=l+r>>1;

        vector<vector<int>>dp(h+1,vector<int>(w+1,-1));
        dp[1][1]=a[1][1]+m;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(dp[i-1][j]>0) dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][j]);
                if(dp[i][j-1]>0) dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i][j]);
            }
        }

        if(dp[h][w]>0) r=m-1;
        else l=m+1;
    }
    if(l) l--;
    cout<<l<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

