#include <bits/stdc++.h>
using namespace std;

int a[1010];
int b[1010];
int dp[1010][1010];
int c1,c2,k;
bool ck(int x)
{
    vector<vector<int>>res(c1+1,vector<int>(c2+1,0));
    res[0][0]=1;
    for(int i=0;i<=c1;i++)
    {
        for(int j=0;j<=c2;j++)
        {
            
            if(!i&&!j) continue;
            
            if(dp[i][j]>x) continue;

            if(i-1>=0&&dp[i-1][j]+1<=x&&res[i-1][j]==1) res[i][j]=1;

            if(j-1>=0&&dp[i][j-1]+1<=x&&res[i][j-1]==1) res[i][j]=1;
        }
    }
    return res[c1][c2]==1;
}
void solve()
{
    cin>>c1>>c2>>k;
    for(int i=1;i<=c1;i++) cin>>a[i];
    for(int i=1;i<=c2;i++) cin>>b[i];


    for(int i=0;i<=c1;i++)
    {
        map<int,int>mp;
        int ans=0;
        for(int i1=1;i1<=i;i1++)
        {
            mp[a[i1]]++;
            if(mp[a[i1]]%k==0) ans+=k;
        }

        dp[i][0]=i-ans;
        for(int j=1;j<=c2;j++)
        {
            mp[b[j]]++;
            if(mp[b[j]]%k==0) ans+=k;
            dp[i][j]=i+j-ans;
        }
    }
    int l=1,r=c1+c2;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) r=m-1;
        else l=m+1;
    }
    cout<<l<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
